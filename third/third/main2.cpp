#include <iostream>
#include <fstream>
#include <complex>
#include <ctime>
#include <cmath>
using namespace std;

int SLAU(complex <float>** matrica_a, int n, complex <float>* massiv_b, complex <float>* x){
	int i, j, k, r;
	complex <float> c, M, s;
	float max;
	complex <float>** a, * b;
	a = new complex <float> *[n];
	for (i = 0; i < n; i++)
		a[i] = new complex <float>[n];
	b = new complex <float>[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = matrica_a[i][j];
	for (i = 0; i < n; i++)
		b[i] = massiv_b[i];
	for (k = 0; k < n; k++)
	{
		max = abs(a[k][k]);
		r = k;
		for (i = k + 1; i < n; i++)
			if (abs(a[i][k]) > max)
			{
				max = abs(a[i][k]);
				r = i;
			}
		for (j = 0; j < n; j++)
		{
			c = a[k][j];
			a[k][j] = a[r][j];
			a[r][j] = c;
		}
		c = b[k];
		b[k] = b[r];
		b[r] = c;
		for (i = k + 1; i < n; i++)
		{
			for (M = a[i][k] / a[k][k], j = k; j < n; j++)
				a[i][j] -= M * a[k][j];
			b[i] -= M * b[k];
		}
	}
	if (abs(a[n - 1][n - 1]) == 0)
		if (abs(b[n - 1]) == 0)
			return -1;
		else return -2;
	else
	{
		for (i = n - 1; i >= 0; i--)
		{
			for (s = 0, j = i + 1; j < n; j++)
				s += a[i][j] * x[j];
			x[i] = (b[i] - s) / a[i][i];
		}
		return 0;
	}
	for (i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	delete[] b;
}

int INVERSE(complex <float>** a, int n,complex <float>** y){
	int i, j, res;
	complex <float>* b, * x;
	b = new complex <float>[n];
	x = new complex <float>[n];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if (j == i)
				b[j] = 1;
			else b[j] = 0;
		res = SLAU(a, n, b, x);
		if (res != 0)
			break;
		else
			for (j = 0; j < n; j++)
				y[j][i] = x[j];
	}
	delete[] x;
	delete[] b;
	if (res != 0)
		return -1;
	else
		return 0;
}
int main() {
    srand(time(NULL));
    int size;
    cin >> size;

    complex<float> **A = new complex<float> *[size], **B = new complex<float> *[size], **prom_C = new complex<float> *[size], **C = new complex<float> *[size], **reverse_C = new complex<float> *[size];
    for (int i = 0; i < size; i++) {
        A[i] = new complex<float>[size];
        B[i] = new complex<float>[size];
        prom_C[i] = new complex<float>[size];
        reverse_C[i] = new complex<float>[size];
        C[i] = new complex<float>[size];
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

    cout << "\nprom_C:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] *= A[i][j];
            B[i][j] *= B[i][j];
            prom_C[i][j] = A[i][j] + B[i][j];
            cout << prom_C[i][j] << " ";
        }
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

	if (!INVERSE(C, size, reverse_C)) {
		cout << endl << "Обратная матрица C" << endl;
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++)
				cout << reverse_C[i][j] << " ";
            cout << endl;
        }
	}

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
