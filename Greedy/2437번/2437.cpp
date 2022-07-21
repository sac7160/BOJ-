//2437번

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

	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		nums.push_back(enter);
	}
	sort(nums.begin(), nums.end());

	int sum = 0;
	if (nums[0] != 1) {
		cout << 1;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (nums[i] > sum + 1) break;
		sum += nums[i];
	}
	cout << sum + 1;
}