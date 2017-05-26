#include <iostream>

using namespace std;

int main() {
	int i=0, x=1, plus=0, minus=0;

	for (;; i++) 
	{	
		cin >> x;
		if (x == 0) {
			break;
		}
		else if (x > 0) {
			plus += 1;
		}
		else if (x < 0) {
			minus += 1;
		}
	}
	cout << "Dodatnie: " << plus << "\nUjemne: " << minus << "\nInsert 0 to end program";
	cin >> x;
	
	return 0;
}