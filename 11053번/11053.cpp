//11053번

#include <iostream>

int main()
{
	using namespace std;

	int n;
	int dp[1001];
	int nums[1001];

	fill_n(dp, 1001, 1);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i - 1; j++)
		{
			if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	int max = dp[0];
	for (int i = 1; i < n; i++)
	{
		if (max < dp[i])
			max = dp[i];
	}

	cout << max;

}