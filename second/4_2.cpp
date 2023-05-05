#include <iostream>
#include <cmath>
#include <ctime>
#include <chrono>
using namespace std;

void multiplication_mat(int** A, int** B, int** C, int n, string choose) {
	if (choose == "IJK") {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				C[i][j] = 0;
				for (int k = 0; k < n; k++)
					C[i][j] += A[i][k] * B[k][j];
			}
	}

	if (choose == "IKJ") {
		for (int i = 0; i < n; i++)
			for (int k = 0; k < n; k++) {
				C[i][k] = 0;
				for (int j = 0; j < n; j++)
					C[i][j] += A[i][k] * B[k][j];
			}
	}

	if (choose == "JIK") {
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n; i++) {
				C[j][i] = 0;
				for (int k = 0; k < n; k++)
					C[i][j] += A[i][k] * B[k][j];
			}
	}

	if (choose == "JKI") {
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) {
				C[j][k] = 0;
				for (int i = 0; i < n; i++)
					C[i][j] += A[i][k] * B[k][j];
			}
	}

	if (choose == "KIJ") {
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++) {
				C[k][i] = 0;
				for (int j = 0; j < n; j++)
					C[i][j] += A[i][k] * B[k][j];
			}
	}

	if (choose == "KJI") {
		for (int k = 0; k < n; k++)
			for (int j = 0; j < n; j++) {
				C[k][j] = 0;
				for (int i = 0; i < n; i++)
					C[i][j] += A[i][k] * B[k][j];
			}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
}

int main() {
    cout << "Размер матриц:\tIJK\tIKJ\tJIK\tJKI\tKIJ\tKJI\n";
    srand(time(NULL));
    int size_matr = 0;
    while(size_matr < 2000){
    	size_matr+=500;
        cout << size_matr << "\t\t";
	    int **Matr1 = new int*[size_matr], **Matr2 = new int*[size_matr], **C = new int*[size_matr];
		for(int i = 0; i < size_matr; i++){
	        Matr1[i] = new int[size_matr];
	        Matr2[i] = new int[size_matr];
	        C[i] =  new int [size_matr];
	    }
	    for(int i = 0; i < size_matr; i++)
	        for(int j = 0; j < size_matr; j++){
	            Matr1[i][j] = rand()%1000;
	            Matr2[i][j] = rand()%1000;
	        }
	    auto timeNULL = high_resolution_clock::now();
        multiplication_mas(Matr1, Matr2, C, size_matr, size2, "IJK");
        auto timeONE = high_resolution_clock::now();
        cout << duration_cast<milliseconds>(timeONE-timeNULL).count()/1000<<"\t";
        timeNULL = high_resolution_clock::now();
        multiplication_mas(Matr1, Matr2, C, size_matr, "IKJ");
        timeONE = high_resolution_clock::now();
        cout<<duration_cast<milliseconds>(timeONE-timeNULL).count()/1000<<"\t";
        timeNULL = high_resolution_clock::now();
        multiplication_mas(Matr1, Matr2, C, size_matr, "JIK");
        timeONE = high_resolution_clock::now();
        cout<<duration_cast<milliseconds>(timeONE-timeNULL).count()/1000<<"\t";
        timeNULL = high_resolution_clock::now();
        multiplication_mas(Matr1, Matr2, C, size_matr, "JKI");
        timeONE = high_resolution_clock::now();
        cout<<duration_cast<milliseconds>(timeONE-timeNULL).count()/1000<<"\t";
        timeNULL = high_resolution_clock::now();
        multiplication_mas(Matr1, Matr2, C, size_matr, "KIJ");
        timeONE = high_resolution_clock::now();
        cout<<duration_cast<milliseconds>(timeONE-timeNULL).count()/1000<<"\t";
        timeNULL = high_resolution_clock::now();
        multiplication_mas(Matr1, Matr2, C, size_matr, "KJI");
        timeONE = high_resolution_clock::now();
        cout<<duration_cast<milliseconds>(timeONE-timeNULL).count()/1000<<"\n";

        for(int i = 0; i < size_matr; i++){
            delete[]Matr1[i];
            delete[]Matr2[i];
            delete[]C[i];
        }
        delete[]Matr1; delete[]Matr2; delete[]C;
    }
	return 0;
}
