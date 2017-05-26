#include <iostream>

using namespace std;

class liczba{
	int wart_licz;

public:
	void wczytaj();
	void wypisz();
	void nadaj(int n);
	int wartosc();
	unsigned int abs();
};

void liczba::wczytaj(){
	cin >> wart_licz;
}

void liczba::wypisz(){
	cout << wart_licz;
}

void liczba::nadaj(int n){
	wart_licz = n;
}

int liczba::wartosc(){
	return wart_licz;
}

unsigned int liczba::abs(){
	if (wart_licz >= 0){
		return wart_licz;
	} else {
		return -wart_licz;
	}
}

int main(){
	liczba licz;
	int x = 0;

	cout << "Podaj liczbe: " << endl;
	licz.wczytaj();

	cout << "Wypisz liczbe: " << endl;
	licz.wypisz();

	cout << "Ustaw liczbe (-100)" << endl;
	licz.nadaj(-100);

	cout << "Obeczna liczba: " << licz.wartosc() << endl;

	cout << "abs: " << licz.abs() << endl;

	cin.get();
	return 0;
}