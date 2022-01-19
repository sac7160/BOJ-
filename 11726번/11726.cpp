//11726번

#include <iostream>

using namespace std;
int dp[1001];

int count(int x)
{
	if (x == 0) return 1;
	if (x == 1) return 1;
	if (dp[x] != 0) return dp[x];

	dp[x] = count(x - 2) + count(x - 1);
	dp[x] %= 10007;

	return dp[x];
}

int main()
{
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 1;
	count(n);
	cout << dp[n];
	
}