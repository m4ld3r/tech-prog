#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
void multiplication_mas(int* A, int* B, int* C, int size1, int size2, string choose) {
    if (choose == "IJK")
        for (int i = 0; i < size1; i++)
            for (int j = 0; j < size1; j++) {
                B[i * size1 + j] = 0;
                for (int k = 0; k < size1; k++)
                    B[i * size1 + j] += A[i * size1 + k]
                    * C[k * size1 + j];
            }
    if (choose == "IKJ")
        for (int i = 0; i < size1; i++)
            for (int k = 0; k < size1; k++) {
                B[i * size1 + k] = 0;
                for (int j = 0; j < size1; j++)
                    B[i * size1 + j] += A[i * size1 + k]
                    * C[k * size1 + j];
            }
    if (choose == "JIK")
        for (int j = 0; j < size1; j++)
            for (int i = 0; i < size1; i++) {
                B[j * size1 + i] = 0;
                for (int k = 0; k < size1; k++)
                    B[i * size1 + j] += A[i * size1 + k]
                    * C[k * size1 + j];
            }
    if (choose == "JKI")
        for (int j = 0; j < size1; j++)
            for (int k = 0; k < size1; k++) {
                B[j * size1 + k] = 0;
                for (int i = 0; i < size1; i++)
                    B[i * size1 + j] += A[i * size1 + k]
                    * C[k * size1 + j];
            }
    if (choose == "KIJ")
        for (int k = 0; k < size1; k++)
            for (int i = 0; i < size1; i++) {
                B[k * size1 + i] = 0;
                for (int j = 0; j < size1; j++)
                    B[i * size1 + j] += A[i * size1 + k]
                    * C[k * size1 + j];
            }
    if (choose == "KJI")
        for (int k = 0; k < size1; k++)
            for (int j = 0; j < size1; j++) {
                B[k * size1 + j] = 0;
                for (int i = 0; i < size1; i++)
                    B[i * size1 + j] += A[i * size1 + k]
                    * C[k * size1 + j];
            }
}

int main() {
    srand(time(NULL));
    cout << "\n\tРазмер массива:\tIJK\tIKJ\tJIK\tJKI\tKIJ\tKJI\n";
    int size1 = 0;
    while (size1 < 2000) {
        size1 += 500;
        cout << "\t" << size1 << " * " << size1 << "\t";
        int size2 = size1 * size1, * mas_A = new int[size2], * mas_C = new int[size2], * mas_B = new int[size2];
        for (int i = 0; i < size2; i++) {
            mas_A[i] = rand() % 100;
            mas_C[i] = rand() % 100;
        }
        auto timeNULL = high_resolution_clock::now();
        multiplication_mas(mas_A, mas_B, mas_C, size1, size2, "IJK");
        auto timeONE = high_resolution_clock::now();
        cout << duration_cast<milliseconds>(timeONE-timeNULL).count()/1000<<"\t";
        timeNULL = high_resolution_clock::now();
        multiplication_mas(mas_A, mas_B, mas_C, size1, size2, "IKJ");
        timeONE = high_resolution_clock::now();
        cout<<duration_cast<milliseconds>(timeONE-timeNULL).count()/1000<<"\t";
        timeNULL = high_resolution_clock::now();
        multiplication_mas(mas_A, mas_B, mas_C, size1, size2, "JIK");
        timeONE = high_resolution_clock::now();
        cout<<duration_cast<milliseconds>(timeONE-timeNULL).count()/1000<<"\t";
        timeNULL = high_resolution_clock::now();
        multiplication_mas(mas_A, mas_B, mas_C, size1, size2, "JKI");
        timeONE = high_resolution_clock::now();
        cout<<duration_cast<milliseconds>(timeONE-timeNULL).count()/1000<<"\t";
        timeNULL = high_resolution_clock::now();
        multiplication_mas(mas_A, mas_B, mas_C, size1, size2, "KIJ");
        timeONE = high_resolution_clock::now();
        cout<<duration_cast<milliseconds>(timeONE-timeNULL).count()/1000<<"\t";
        timeNULL = high_resolution_clock::now();
        multiplication_mas(mas_A, mas_B, mas_C, size1, size2, "KJI");
        timeONE = high_resolution_clock::now();
        cout<<duration_cast<milliseconds>(timeONE-timeNULL).count()/1000<<"\n";
        delete[]mas_A, delete[]mas_B, delete[]mas_C;
    }
    return 0;
}