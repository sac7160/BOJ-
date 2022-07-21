//11048번

#include <iostream>

using namespace std;

int n, m;
int candy[1001][1001];
int dp[1001][1001];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> candy[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int result = 0;
			result = max(dp[i][j - 1], dp[i - 1][j]);
			dp[i][j] = result + candy[i][j];
		}
	}

	cout << dp[n][m];
}