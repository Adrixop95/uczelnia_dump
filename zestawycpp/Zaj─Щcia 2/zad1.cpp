
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	double a, b, c, delta, x0, x1, x2, x3;

	cout << "Podaj pierwsza liczbe" << endl;
	cin >> a;
	cin.get();

	cout << "Podaj druga liczbe" << endl;
	cin >> b;
	cin.get();

	cout << "Podaj trzecia liczbe" << endl;
	cin >> c;
	cin.get();

	if (a == 0) {
		cout << "To nie jest rownanie kwadratowe" << endl;
		x3 = -c / b;
		cout << x3 << endl;
	}
	else
	{
		delta = (b*b) - (4 * a*c);
		cout << "Delta wynosi " << delta << endl << endl;
		if (delta>0)
		{
			x1 = (-b - sqrt(delta)) / (2 * a);
			x2 = (-b + sqrt(delta)) / (2 * a);
		}
		else if (delta == 0)
		{
			x1 = -b / 2 * a;
			x2 = x1;
		}
		else
		{
			cout << "brak rozwiazan" << endl;
		}
		cout << "Pierwiastki rownania wynosza " << x1 << "," << x2 << endl << endl;

	}

	cin.get();
	return 0;
}
