//1940번

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,m,enter;
	cin >> n >> m;
	vector<int>nums;

	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		nums.push_back(enter);
	}
	sort(nums.begin(), nums.end());

	int count = 0;

	for (int i = 0; i < n-1; i++)
	{
		int j = 1;
		while (i + j < n)
		{
			if (nums[i] + nums[i + j] == m)
			{
				count++;
				break;
			}
			else j++;
		}
	}
	cout << count;
}

