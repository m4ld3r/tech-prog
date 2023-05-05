#include <iostream>
using namespace std;

bool Check_Pal(int ch);
bool Check_Simple(int ch);

struct list {
	int info;
	list* next;
};

void Insert_Element(int data, list*& p) {
	list* r = new list;
	r->info = data;
	r->next = p->next;
	p->next = r;
	p = r;
}

void Print_List(list* ll, char check) {
	cout << endl;
	if(check == 'p') cout << "Список чисел-палиндромов:\n";
	if(check == 's') cout << "Список простых чисел:\n";
	while (ll != NULL) {
		if(check == 'p') if(Check_Pal(ll->info)) cout << ll->info << '\t';
		if(check == 's') if(Check_Simple(ll->info)) cout << ll->info << '\t';
		ll = ll->next;
	}
	cout << endl;
}

int main(){
	list* ll = NULL;
	int ch, a, n, m, kol_n = 0, kol_m = 0;

	cout << "Последовательно (через space или enter) введите 'a', кол-во палиндромов 'n' и простых чисел 'm':\n";
	cin >> a >> n >> m;

	cout << "\nВведите ч-ла:\n";
	cin >> ch;
	if (kol_m < m || kol_n < n) {
		ll = new (list);
		ll->info = ch;
		ll->next = NULL;
		if(Check_Pal(ch) && ch > a) kol_n++;
		if(Check_Simple(ch) && ch > a) kol_m++;
		cin >> ch;
		list* p = ll;
		while (kol_m < m || kol_n < n) {
			Insert_Element(ch, p);
			if(Check_Pal(ch) && ch > a) kol_n++;
			if(Check_Simple(ch) && ch > a) kol_m++;
			cin >> ch;
		}
	}

	Print_List(ll, 'p');
	Print_List(ll, 's');

	return 0;
}

bool Check_Pal(int ch){
	int reverse = 0, remainder = 0, dubl = ch;
	while (ch != 0){
		remainder = ch % 10;
		reverse = reverse * 10 + remainder;
		ch /= 10;
	}

	if (reverse == dubl) return true;
	else return false;
}

bool Check_Simple(int ch){
	int kol = 0;
	for (int i = 1; i <=ch; i++) if(ch % i == 0) kol++;
	
	if(kol == 2) return true;
	else return false;
}