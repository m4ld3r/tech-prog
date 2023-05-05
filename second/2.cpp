#include <iostream>
#include <ctime>
using namespace std;

bool Check_Chet(int ch){
    int summa = 0;
    
    while(ch){
        summa += ch % 10;
        ch /= 10;
    }

    if(summa % 2 == 0) return true;
    return false;
}

int main(){
    cout << "n: ";
    int n; cin >> n;
    int **A = new int*[n], *B = new int[n];
    for(int i = 0; i < n; i++) A[i] = new int[n];
    
    cout << "A:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> A[i][j];
        B[i] = 0;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(Check_Chet(A[i][j]))B[i]++;

    for(int j = 0; j < n; j++){
        int mx = A[0][j], mn = A[0][j], i1 = 0, i2 = 0, j1 = j, j2 = j; 
        for(int i = 0; i < n; i++){
            if(A[i][j] > mx){
                mx = A[i][j];
                i1 = i;
                j1 = j;
            }
            if(A[i][j] < mn){
                mn = A[i][j];
                i2 = i;
                j2 = j;
            }
        }
         swap(A[i1][j1],A[i2][j2]);
    }

    cout << "\nA:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << A[i][j] << " ";
        cout << endl;
    }

    cout << "\nB: ";
    for(int i = 0; i < n; i++) cout << B[i] << " ";
    cout << endl;

    for(int i = 0; i < n; i++) delete[] A[i];
    delete []A; delete []B;

	return 0;
}
