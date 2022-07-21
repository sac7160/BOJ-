//1449번

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,l,enter;
	cin >> n >> l;
	vector<int>nums;

	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		nums.push_back(enter);
	}

	sort(nums.begin(), nums.end());

	int count = 1;
	int start = nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		if (nums[i] - start < l) continue;
		else
		{
			count++;
			start = nums[i];
		}
	}
	cout << count;
}