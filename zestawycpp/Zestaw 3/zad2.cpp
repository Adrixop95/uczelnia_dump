#include <iostream>

using namespace std;

int Fibonacci(int n)
{
	if (n <= 0) {
		return 0;
	}
	else if (n == 1){
		return 1;
	}
	else { 
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int main(void)
{
	int a;
	cout << "Podaj liczbe: " << endl;
	cin >> a;

	cout << "Wartosc ciagu fibonacciego dla "<< a <<" to: " << Fibonacci(a) << endl;

	system("pause");
	cin.get();
	return 0;
}