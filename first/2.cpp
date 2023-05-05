#include <iostream>
using namespace std;

bool Check_Simple(int ch){
	int kol = 0;
	for (int i = 1; i <=ch; i++) if(ch % i == 0) kol++;

	if(kol == 2) return true;
	else return false;
}

int Del(int ch){
	int del = 0;
	for(int i = 1; i < ch; i++) if(ch % i == 0) del = i;
	return del;
}

int main(){
	int ch, n, kol_n = 0;
	cout << "Введите требуемое кол-во простых чисел n:  ";
	cin >> n;
	cout << "\nВведите числo:\n";
	cin >> ch;
	if(Check_Simple(ch)) kol_n++;
	cout << "наибольший делитель " << ch << ":  " << Del(ch) << endl;

	while(kol_n < n){
		cout << "\nВведите следующее число:\n";
		cin >> ch;
		if(Check_Simple(ch))kol_n++;
		cout << "наибольший делитель " << ch << ":  " << Del(ch) << endl;
	}
	return 0;
}