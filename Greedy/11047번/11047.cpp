#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int* coins = new int[n];

	for (int i = 0; i < n; i++) cin >> coins[i];

	int sum = 0;

	for (int i = n-1; i >= 0; i--)
	{
		if (coins[i] <= k)
		{
			sum += k / coins[i];
			k = k % coins[i];
		}
	}

	cout << sum;

	delete[] coins;
}