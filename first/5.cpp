#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, x;
	float y = 0;

	cout << "Введите:\n";
	cout << "n:  "; cin >> n;
	cout << "x:  "; cin >> x;

	y+=x;
	for(int i = 1; i <= n; i++) y+=float(pow(x, i+1)/(i*pow(2, i)));

	cout << "y:  " << y << endl;
	return 0;
}