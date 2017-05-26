#include <iostream>

using namespace std;

int main()
{

	int n;

	cout << "Wprowadz wysokosc: ";
	cin >> n;
	cout << endl;

	for (int i = 1; i <= n - 1; i++)
	{
		for (int k = 1; k <= n - i - 1; k++)
		{
			cout << " ";
		}
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}


	cin.get();
	return 0;
}