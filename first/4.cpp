#include <iostream>
#include <cmath>
using namespace std;

int Fact(int n){
    int pr = 1;
    while(n > 0){
        pr *= n;
        n-=1;
    }
    return pr;
}

int main(){
    float h, y, e;
    int n;
    cout << "h:  "; cin >> h;
    cout << "e:  "; cin >> e;
    for(float x = 0; x <= 1; x+=h){
        cout << "\nx: " << x;
        float s = 0;
        n = 0;
        while(fabs(((pow(n,2)+1)/Fact(n))*pow(x/2, n)) >= e){
		    s += ((pow(n,2)+1)/Fact(n))*pow(x/2, n);
            n++;
        }
	    y = (pow(x,2)/4 + x/2 + 1)*exp(x/2);
        cout << "\ts: " << s << "\ty: " << y;
    }
	return 0;
}
((((x^2)/4)+(x/2)+1)*E^(x/2))
(((n^2+1)/n!)*(x/2)^n)
