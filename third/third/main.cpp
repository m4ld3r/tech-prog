#include <iostream>
#include <fstream>
#include <cmath>
#include <complex>
#include <string>
using namespace std;

complex<int> Determ(complex<int>**matr, int n){
    complex<int> det;
    if(n == 1) det = matr[n-1][n-1];
    if (n == 2)
        det = matr[0][0]*matr[1][1] - matr[0][1]*matr[1][0];
    if(n == 3){
        det = matr[0][0]*matr[1][1]*matr[2][2] + matr[0][1]*matr[1][2]*matr[2][0] + matr[1][0]*matr[2][1]*matr[0][2];
        det -= matr[2][0]*matr[1][1]*matr[0][2] - matr[1][0]*matr[0][1]*matr[2][2] - matr[2][1]*matr[1][2]*matr[0][0];
    }
    return det;
}

int main(){
    ifstream size_matrix("matrix_A.txt"), matr_A("matrix_A.txt"), matr_B("matrix_B.txt");
    if(size_matrix.is_open() && matr_A.is_open() && matr_B.is_open()){
        int n = 0, buf;
        string number;
        char symbol;
        
        while(symbol != '\n'){
            size_matrix >> number; n++;
            size_matrix.get(symbol);
        }
        n /= 2;
        size_matrix.close();

        complex<int> **A = new complex<int>*[n], **B = new complex<int>*[n], **C_T = new complex<int>*[n], **C = new complex<int>*[n];
        for(int i = 0; i < n; i++){
            A[i] = new complex<int>[n];
            B[i] = new complex<int>[n];
            C_T[i] = new complex<int>[n];
            C[i] = new complex<int>[n];
            for(int j = 0; j < n; j++){
                matr_A >> buf; A[i][j].real(buf);
                matr_A >> buf; A[i][j].imag(buf);
                matr_B >> buf; B[i][j].real(buf);
                matr_B >> buf; B[i][j].imag(buf);
            }
        }
        matr_A.close();
        matr_B.close();
        
        cout << "A:\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cout << A[i][j] << " ";
            cout << endl;
        }

        cout << "\nB:\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cout << B[i][j] << " "; 
            cout << endl;
        }
/*Для заданных матриц комплексных чисел А(n×n) и B(n×n) найти C= ((A^2 +B^2 ))^T. Вычислить C^-1.*/
        cout << "\nC:\n";
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                C_T[j][i] = A[i][j]*A[i][j] + B[i][j]*B[i][j];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cout << C_T[i][j] << " ";
            cout << endl;
        }

        cout << "\nC^-1:\n";
        complex<int> det = Determ(C_T, n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                C[i][j] = C_T[j][i] / det;
                cout << C[i][j] << " ";
            }
            cout << endl;
        }

        for(int i = 0; i < n; i++){
            delete[]A[i]; delete[]B[i];
            delete[]C_T[i]; delete[]C[i];
        }
        delete[]A; delete[]B;
        delete[]C_T; delete[]C;
                
    }        
    return 0;
}
