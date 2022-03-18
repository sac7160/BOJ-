//1448번

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	
	using namespace std;
	int n;
	int enter;
	vector<int>nums;
	cin >> n;
	while (n--)
	{
		cin >> enter;
		nums.push_back(enter);
	}
	sort(nums.begin(), nums.end(), greater<>());
	
	int maxIndex = 0;
	for (int i = maxIndex+1; i < nums.size(); i++)
	{
		for (int j = i+1 ; j < nums.size(); j++)
		{
			if (nums[maxIndex] < nums[i] + nums[j])
			{
				cout << nums[maxIndex]+nums[i]+nums[j];
				return 0;
			}
		}
		maxIndex++;
	}
	cout << -1;
}