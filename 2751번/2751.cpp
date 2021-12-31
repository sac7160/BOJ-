#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int* nums = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	sort(nums, nums + n);

	for (int i = 0; i < n; i++)
	{
		cout<< nums[i] << '\n';
	}
	delete[] nums;
}