#include <iostream>
using namespace std;
struct Complex {float Im;float Re;};
Complex Plus(Complex first, Complex second) {
	Complex summa;
	summa.Im = first.Im + second.Im;
	summa.Re = first.Re + second.Re;
	return summa;
}
Complex Minus(Complex first, Complex second) {
	Complex difference;
	difference.Im = first.Im - second.Im;
	difference.Re = first.Re - second.Re;
	return difference;
}
Complex Multiply(Complex first, Complex second) {
	Complex piece;
	piece.Re = first.Re*second.Re - first.Im*second.Im;
	piece.Im = first.Re*second.Im + second.Re*first.Im;
	return piece;
}
Complex Share(Complex first, Complex second) {
	Complex division;
	division.Re = (first.Re*second.Re + first.Im*second.Im) / (pow(second.Re,2)+ pow(second.Im, 2));
	division.Im = (second.Re*first.Im - first.Re*second.Im) / (pow(second.Re, 2) + pow(second.Im, 2));
	return division;
}
int main() {
	setlocale(LC_ALL, "Rus");
	Complex x, num, den, a, b, c, buffer;
	cout << "Последовательно введите действительную и мнимую часть для\na: ";
	cin >> a.Im >> a.Re;
	cout << "b: "; cin >> b.Im >> b.Re;
	cout << "c: "; cin >> c.Im >> c.Re;
	buffer = Multiply(b, b);
	num = Plus(Plus(a, c), Multiply(buffer, b));
	den = Minus(Minus(a, buffer), c);
	x = Share(num, den);
	cout << "\nX.Re: " << x.Re << "\nX.Im:  " << x.Im << endl;
	return 0;
}