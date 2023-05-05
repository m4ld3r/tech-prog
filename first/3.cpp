#include <iostream>
using namespace std;

int main(){
	int n, sum = 0;
	cout << "\n\tВведите кол-во чисел n:  "; cin >> n;
    cout << "\t";
	for(int i = 1; i <= n; i++)
        if(i % 7 == 0){
            cout << i << " "; 
            sum += i*i;
        }
	cout << "\n\tПолученная сумма из первых " << n << " чисел:  " << sum << endl << endl;
}
