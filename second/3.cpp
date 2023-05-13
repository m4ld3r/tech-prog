#include <iostream>
#include <cmath>
using namespace std;

bool Check(double** I, double** E) {
    int** I_pow_two = new int* [3];
    double **second_I = new double*[3];
    for(int i = 0; i < 3; i++) {
        second_I[i] = new double[3];
        for(int j = 0; j < 3; j++)
            second_I[i][j] = I[i][j];
    }

    for (int i = 0; i < 3; i++) {
        I_pow_two[i] = new int[3];
        for (int j = 0; j < 3; j++) {
            I_pow_two[i][j] = 0;
            for (int k = 0; k < 3; k++)
                I_pow_two[i][j] += I[i][k] * second_I[k][j];
            /* if (I_pow_two[i][j] != E[i][j]) return false; */
        }
    }
    cout << "\nI^2:\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout << I_pow_two[i][j] << " ";
        cout << endl;
    }
    return false;
}

double* Gauss(double** I, double* Units){
    double* X, max;
    int k, index;
    const double eps = 0.00001;  
    X = new double[3];
    k = 0;
    while (k < 3) {
        max = abs(I[k][k]);
        index = k;
        for (int i = k + 1; i < 3; i++){
            if (abs(I[i][k]) > max){
                max = abs(I[i][k]);
                index = i;
            }
        }
        for (int j = 0; j < 3; j++){
            double temp = I[k][j];
            I[k][j] = I[index][j];
            I[index][j] = temp;
        }
        double temp = Units[k];
        Units[k] = Units[index];
        Units[index] = temp;
        for (int i = k; i < 3; i++){
            double temp = I[i][k];
            if (abs(temp) < eps) continue; 
            for (int j = 0; j < 3; j++)
                I[i][j] = I[i][j] / temp;
            Units[i] = Units[i] / temp;
            if (i == k)  continue;
            for (int j = 0; j < 3; j++)
                I[i][j] = I[i][j] - I[k][j];
            Units[i] = Units[i] - Units[k];
        }
        k++;
    }
    for (k = 2; k >= 0; k--){
        X[k] = Units[k];
        for (int i = 0; i < k; i++)
            Units[i] = Units[i] - I[i][k] * X[k];
    }
    return X;
}

int main() {
    double** P = new double* [3], ** E = new double* [3], ** I = new double* [3], * Units = new double[3], *X;
    for (int i = 0; i < 3; i++) {
        P[i] = new double[3];
        E[i] = new double[3];
        I[i] = new double[3];
        Units[i] = 1;
        for (int j = 0; j < 3; j++){
            if(i == j) E[i][j] = 1;
            else E[i][j] = 0;
        }
    }
    P[0][0] = -26;
    P[0][1] = -18;
    P[0][2] = -27;
    P[1][0] = P[1][2] = 21;
    P[1][1] = 15;
    P[2][0] = 12;
    P[2][1] = 8;
    P[2][2] = 13;

    cout << "2*P:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            I[i][j] = 2 * P[i][j];
            if(i == j){
                I[i][j] -= E[i][j];
            }

            /* cout << I[i][j] << " "; */
            cout << 2 * P[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nI:\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            cout << I[i][j] << " ";
        cout << endl;
    }

    cout << "\nX:\n";
    X = Gauss(I, Units);
    for (int i = 0; i < 3; i++)
        cout << X[i] << " ";
    cout << endl;

    if (Check(I, E))cout << "\nПроверка пройдена успешно\n";
    else cout << "\nПроверка пройдена неудачно\n";
    cout << endl;
    return 0;
}
