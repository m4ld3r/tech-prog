#include <iostream>
#include <fstream>
#include <complex>
#include <ctime>
#include <cmath>
using namespace std;

complex<double>Det(complex<double>**matr, int size){
    if(size == 2)
        return (matr[0][0]*matr[1][1] - matr[0][1]*matr[1][0]);
    if(size == 3)
        return 0;
}

complex<double> Reverse_Matr(complex<double>**matr, int size){
    complex<double>det=Det(matr, size);
    if(det.imag()!=0 || det.real() != 0){
        complex<double>**dubl_matr = new complex<double>*[size];
        for(int i = 0; i < size; i++){
            dubl_matr[i] = new complex<double>[size];
            for(int j = 0; j < size; j++)
                dubl_matr[i][j] = matr[i][j];
        }

        if(size == 2){
            matr[0][0] = dubl_matr[1][1];
            matr[0][1] = dubl_matr[1][0]*-1.0;
            matr[1][0] = dubl_matr[0][1]*-1.0;
            matr[1][1] = dubl_matr[0][0];
        }

        if(size == 3){
            matr[0][0] = dubl_matr[1][1]*dubl_matr[2][2]-dubl_matr[1][2]*dubl_matr[2][1];
            matr[0][1] = (dubl_matr[1][0]*dubl_matr[2][2]-dubl_matr[1][2]*dubl_matr[2][0])*-1.0;
            matr[0][2] = dubl_matr[1][1]*dubl_matr[2][1]-dubl_matr[1][1]*dubl_matr[2][0];
            matr[1][0] = (dubl_matr[0][1]*dubl_matr[2][2]-dubl_matr[0][2]*dubl_matr[2][0])*-1.0;
            matr[1][1] = dubl_matr[0][0]*dubl_matr[2][2]-dubl_matr[0][2]*dubl_matr[2][0];
            matr[1][2] = (dubl_matr[0][0]*dubl_matr[2][1]-dubl_matr[2][0]*dubl_matr[0][1])*-1.0;
            matr[2][0] = dubl_matr[0][1]*dubl_matr[1][2]-dubl_matr[0][2]*dubl_matr[1][1];
            matr[2][1] = (dubl_matr[0][0]*dubl_matr[1][2]-dubl_matr[0][2]*dubl_matr[1][0])*-1.0;
            matr[2][2] = dubl_matr[0][0]*dubl_matr[1][1]-dubl_matr[1][0]*dubl_matr[0][1];
        }
    }
    return det;
}
int main() {
    srand(time(NULL));
    int size;
    cin >> size;

    complex<double> **A = new complex<double> *[size], **B = new complex<double> *[size], **prom_C = new complex<double> *[size], **C = new complex<double> *[size], **reverse_C = new complex<double> *[size];
    for (int i = 0; i < size; i++) {
        A[i] = new complex<double>[size];
        B[i] = new complex<double>[size];
        prom_C[i] = new complex<double>[size];
        reverse_C[i] = new complex<double>[size];
        C[i] = new complex<double>[size];
        for (int j = 0; j < size; j++) {
            A[i][j].real(1 + rand() % 14);
            A[i][j].imag(1 + rand() % 14);
            B[i][j].real(1 + rand() % 14);
            B[i][j].imag(1 + rand() % 14);
        }
    }

    cout << "\nA:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) cout << A[i][j] << " ";
        cout << endl;
    }

    cout << "\nB:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) cout << B[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[j][i] = prom_C[i][j];
        }
    }

    cout << "\nC^T:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) cout << C[i][j] << " ";
        cout << endl;
    
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            prom_C[j][i] = C[i][j];
        }
    }

    complex<double>det;
    det=Reverse_Matr(prom_C, size);
    if(det.imag() != 0 || det.real() != 0){
        cout << "\nC^-1.0:\n";
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++)
                cout << prom_C[i][j] << "/" << det << "  ";
            cout << endl;
        }
    }
    else cout << "\nОбратная матрица С не существует\n";

    for (int i = 0; i < size; i++) {
        delete[]A[i];
        delete[]B[i];
        delete[]C[i];
        delete[]prom_C[i];
        delete[]reverse_C[i];
    }
    delete[]A;
    delete[]B;
    delete[]C;
    delete[]reverse_C;
    delete[]prom_C;
    return 0;
}
