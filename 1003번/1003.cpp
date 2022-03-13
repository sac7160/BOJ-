//1003번

#include <iostream>


int count_0[42];
int count_1[42];



int fib0(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else if (n == 1)
	{
		return 0;
	}

	if (count_0[n] == -1) count_0[n] = fib0(n - 2) + fib0(n - 1);

	return count_0[n];
}

int fib1(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	if (count_1[n] == -1) count_1[n] = fib1(n - 2) + fib1(n - 1);
	return count_1[n];
}

int main()
{
	using namespace std;
	fill_n(count_0, 43, -1);
	fill_n(count_1, 43, -1);
	/*count_0[0] = 1;
	count_1[0] = 0;
	count_0[1] = 0;
	count_1[1] = 1;*/

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << fib0(n) << " " << fib1(n) << '\n';
	}
}