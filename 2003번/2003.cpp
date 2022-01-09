//2003번

#include <iostream>
#include <vector>


int main()
{

	using namespace std;
	int n, m,enter;

	cin >> n >> m;
	vector<int>nums;

	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		nums.push_back(enter);
	}

	int sum = 0;
	int startIndex = 0;
	int ans = 0;
	int index = 0;

	while (startIndex != n)
	{
		if (sum == m)
		{
			ans++;
			sum = 0;
			startIndex++;
			index = startIndex;
		}
		else
		{
			if (index == n) break;
			sum += nums[index++];
			if (sum > m)
			{
				startIndex++;
				index = startIndex;
				sum = 0;
			}
		}
	}

	cout << ans;
}