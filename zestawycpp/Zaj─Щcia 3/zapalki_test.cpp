#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int main() {

	srand(time(NULL));

	int zapalki, nowe, spalone, i, wybrana;

	cout << "Podaj liczbe n: " << endl;
	cin >> zapalki;

	nowe = zapalki;
	spalone = 0;

	vector<int> zapamietana;
	vector<int> spalona;

	while (spalone <= zapalki){
		//wybrana = rand() % zapalki;
		zapamietana.push_back(wybrana);

		for (size_t j = 0; j < zapamietana.size(); j++) {
			if (wybrana == zapamietana[j]) {
				cout << "Wybrana to: " << wybrana << endl;
				cout << "Zapamietana to: " << zapamietana[j] << endl;
				spalone += 1;
				cout << "Ilosc spalonych ==: " << spalone << endl;
			}
			else if (wybrana == spalone) {
				cout << "kupa" << endl;
			}
			else if (wybrana != zapamietana[j]) {
				cout << "Wybrana to: " << wybrana << endl;
				cout << "Zapamietana to: " << zapamietana[j] << endl;
				wybrana = spalone;
				spalone += 1;
				cout << "Juz spalona" << endl;
				cout << "Ilosc spalonych !=: " << spalone << endl;
			}
		}
	}

	cout << "Ilosc spalonych w sumie: " << spalone << endl;
	cin.get();
	system("PAUSE");
	return 0;
}