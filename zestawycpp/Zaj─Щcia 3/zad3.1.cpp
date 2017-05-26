#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int x)
{
	for (int i = 2; i <= x / 2; i++)
	{
		if (x%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int input;
	cout << "Podaj liczbe: ";
	cin >> input;
	cin.get();

	vector<long int> prime;
	for (int i = 2; i <= input; i++)
	{
		if (isPrime(i))
		{
			prime.push_back(i);
		}
	}

	for (size_t j = 0; j < prime.size(); j++)
	{
		cout << prime[j] << endl;
	}
	
	cin.get();
	return 0;
}
