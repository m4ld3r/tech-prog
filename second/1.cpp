#include <iostream>
#include <cmath>
using namespace std;

bool Check(int ch){
    int dubl_ch = ch, kol_cifr = 0;
    
    while(dubl_ch){
        kol_cifr += 1;
        dubl_ch /=10;
    }
    int *mas = new int[kol_cifr];
    for(int i = kol_cifr-1; i >= 0; i--){
        mas[i] = ch%10;
        ch /=10;
    }

    if(kol_cifr <= 1){
        delete[]mas;
        return false;
    }
    
    for(int i = 0; i < kol_cifr/2; i++)
        for(int j = kol_cifr-1; j >= kol_cifr/2; j--)
            if(mas[i] == mas[j]){
                delete[]mas;
                return false;
            }
        
    delete[]mas;
    return true;
}

int main(){
	int n, m, kol = 0; long int summa = 0; float pw = 1, st_pow = 0;

    cout << "\nn: "; cin >> n;
    cout << "m: "; cin >> m;
    int **A = new int *[n], **B = new int *[n],**C = new int *[n];
    for (int i = 0; i < n; i++){
       A[i] = new int[m];
       B[i] = new int[m];
       C[i] = new int[m];
    }
    cout << "A:\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            A[i][j] = rand()%10;
            cout << A[i][j] << " ";
            C[i][j] = rand()%10;
            summa += A[i][j];
        }
        cout << endl;
    }   
    
    cout << "\nC:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << C[i][j] << " ";
            if((i == 0 || i == n-1 || j == 0 || j == m-1) && A[i][j] != 0)
                kol++;
            if(Check(A[i][j])){
                st_pow++;
                pw *= A[i][j];
            }          
            B[i][j] = 2*A[i][j]-3*C[i][j];
        }
        cout << endl;
    }

    cout << "\nСумма: " << summa 
         << "\nКол-во ненулевых элементов по периметру: " << kol 
         << "\nCреднее геометрическое чисел: " << pow(pw, 1/st_pow)
         << "\nB:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << B[i][j] << " ";
        cout << endl;
    }
    
    for(int i = 0; i < n; i++) {
        delete []A[i];
        delete []B[i];
        delete []C[i];
    }
    delete []A;
    delete []B;
    delete []C;

	return 0;
}
