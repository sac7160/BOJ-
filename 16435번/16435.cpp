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

	for (int i = 0; i < n; i++)
	{
		if (l >= nums[i]) l++;
		else break;
	}

	cout << l;

}