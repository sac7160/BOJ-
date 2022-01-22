//11055번

#include <iostream>

int main()
{
	using namespace std;

	int n;
	int dp[1001] = { 0, };
	int nums[1001];

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}
	dp[1] = nums[1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i - 1; j++)
		{
			if (nums[j] >= nums[i]) continue;
			if (dp[j] > dp[i]) dp[i] = dp[j];
			else dp[i] = dp[i];
		}
		dp[i] += nums[i];
	}

	int max = dp[1];
	for (int i = 1; i <= n; i++)
	{
		if (max < dp[i])
			max = dp[i];
	}

	cout << max;

}