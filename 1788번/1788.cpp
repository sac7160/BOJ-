//1788번

#include <iostream>

using namespace std;

int a[1000000] = { 0 };

int fib(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	
	if (a[n] == 0 ) a[n] = fib(n - 2) % 1000000000 + fib(n - 1) % 1000000000;

	return a[n]%1000000000;
}

int main()
{
	int n;
	cin >> n;

	if (n == 0) cout << 0 << '\n';
	else if (n > 0) cout << 1 << '\n';
	else if (n < 0)
	{
		if (-n % 2 == 0) cout << -1 << '\n';
		else cout << 1 << '\n';
	}

	if (n >= 0)
	{
		cout << fib(n);
	}
	else if (n < 0)
	{
		cout << fib(-n);
	}
}

