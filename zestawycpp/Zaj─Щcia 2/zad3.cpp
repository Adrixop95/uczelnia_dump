#include <iostream>

using namespace std;

int main() {

	int x = 1, i = 0;

	cout << "Podaj liczbe dodatnia: " << endl;

	for (; x > 0; i++) {
		cin >> x;

		if (x <= 0) {
			break;
		}
	}
	cout << i << endl;

	cin.get();
	return 0;
}