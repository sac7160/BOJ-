//1932번

#include <iostream>

using namespace std;

int index = 0;
int triangle[501][501];
int dp[501][501];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n ; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> triangle[i][j];
		}
	}

	dp[1][1] = triangle[1][1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1) dp[i][j] = triangle[i][j] + dp[i - 1][j];
			else if (j == i) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
		}
	}
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dp[n][i] > max) max = dp[n][i];
	}
	cout << max;
}