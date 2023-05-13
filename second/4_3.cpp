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
    clock_t start, end;
    while (size1 < 2000) {
        size1 += 500;
        cout << "\t" << size1 << " * " << size1 << "\t";
        int size2 = size1 * size1, * mas_A = new int[size2], * mas_C = new int[size2], * mas_B = new int[size2];
        for (int i = 0; i < size2; i++) {
            mas_A[i] = rand() % 100;
            mas_C[i] = rand() % 100;
        }
        start = clock();
        multiplication_mas(mas_A, mas_B, mas_C, size1, size2, "IJK");
        end = clock();
        cout << (double)(end - start) / CLOCKS_PER_SEC << "\t";
        start = clock();
        multiplication_mas(mas_A, mas_B, mas_C, size1, size2, "IKJ");
        end = clock();
        cout << (double)(end - start) / CLOCKS_PER_SEC << "\t";
        start = clock();
        multiplication_mas(mas_A, mas_B, mas_C, size1, size2, "JIK");
        end = clock();
        cout << (double)(end - start) / CLOCKS_PER_SEC << "\t";
        start = clock();
        multiplication_mas(mas_A, mas_B, mas_C, size1, size2, "JKI");
        end = clock();
        cout << (double)(end - start) / CLOCKS_PER_SEC << "\t";
        start = clock();
        multiplication_mas(mas_A, mas_B, mas_C, size1, size2, "KIJ");
        end = clock();
        cout << (double)(end - start) / CLOCKS_PER_SEC << "\t";
        start = clock();
        multiplication_mas(mas_A, mas_B, mas_C, size1, size2, "KJI");
        end = clock();
        cout << (double)(end - start) / CLOCKS_PER_SEC << "\n";
        delete[]mas_A, delete[]mas_B, delete[]mas_C;
    }
    return 0;
}