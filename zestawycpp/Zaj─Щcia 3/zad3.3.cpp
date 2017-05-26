#include <iostream>

using namespace std;

int main()
{
	int x;

	cout << "Podaj dlugosc pi: " << endl;
	cin >> x;
	cin.get();

	double pi = atan(1) * 4;
	cout.precision(x+1);
	cout << pi << endl;

	cin.get();
	return 0;
}