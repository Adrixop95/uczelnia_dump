#include <iostream>

using namespace std;

int NWD_rekurencja_Euklides(int a, int b){
	if (b != 0) {
		return NWD_rekurencja_Euklides(b, a%b);
	}

	return a;
}

int NWD_iteracyjnie_Euklides(int a, int b){
	int x;
	while (b != 0){
		x = b;
		b = a%b;
		a = x;
	}

	return a;
}

int NWD_odejmowanie_Euklides(int a, int b) {
	int c;
	while (a != 0 && b != 0) {
		if (a > b) {
			c = a - b;
			a = c;
		}
		else {
			c = b - a;
			b = c;
		}
	}	

	return a + b;
}

int main() {

	int m, n;

	cout << "Podaj liczbe m: " << endl;
	cin >> m;

	cout << "Podaj liczbe n: " << endl;
	cin >> n;

	cout << "NWD(" << m << "," << n << ") obliczone algorytmem Euklidesa rekurencyjnie uzywającego modulo: " << NWD_rekurencja_Euklides(m, n) << endl;
	cout << "NWD(" << m << "," << n << ") obliczone algorytmem Euklidesa iteracyjnie uzywającego modulo: " << NWD_iteracyjnie_Euklides(m, n) << endl;
	cout << "NWD(" << m << "," << n << ") obliczone algorytmem Euklidesa uzywającego odejmowania: " << NWD_odejmowanie_Euklides(m, n) << endl;

	system("pause");
	cin.get();
	return 0;
}