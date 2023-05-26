#include <iostream>
#include <ctime>
using namespace std;

int Det(int**matr, int size){
    if(size == 2)
        return (matr[0][0]*matr[1][1] - matr[0][1]*matr[1][0]);
    if(size == 3)
        return 0;
}

int Reverse_Matr(int**matr, int size){
    int det=Det(matr, size);
    if(det != 0){
        int**dubl_matr = new int*[size];
        for(int i = 0; i < size; i++){
            dubl_matr[i] = new int[size];
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
    int size = 3, det;
    int**C = new int*[size];
    for(int i = 0; i < size; i++){
        C[i] = new int[size];
        for(int j = 0; j < size; j++){
            C[i][j] = 1+rand()%4;
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    det=Reverse_Matr(C, size);
    if(det != 0){
        cout << "\nC^-1.0:\n";
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++)
                cout << C[i][j] << "/" << det << "  ";
            cout << endl;
        }
    }
    else cout << "\nОбратная матрица С не существует\n";

    for (int i = 0; i < size; i++) 
        delete[]C[i];
    delete[]C;
    return 0;
}
