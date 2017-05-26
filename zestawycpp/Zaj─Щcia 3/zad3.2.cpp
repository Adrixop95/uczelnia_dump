#include <iostream>

using namespace std;

int main() {

	int n, i;

	cout << "Podaj liczbe: " << endl;
	cin >> n;
	cin.get();

	if (n >= 0) {
		for (i = 1; i <= n; i++) {
			if (n%i == 0) {
				cout << i << endl;
			}
		}
	}
	else {
		cout << "Podaj liczbe dodatną!" << endl;
	}


	cin.get();
	return 0;
}