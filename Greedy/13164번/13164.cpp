//13164번

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main()
{
	int n,k,enter;
	cin >> n >> k;
	vector<int>nums;
	vector<int>distance;

	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		nums.push_back(enter);
	}

	for (int i = 0; i < n-1; i++)
	{
		distance.push_back(nums[i+1]-nums[i]);
	}

	sort(distance.begin(), distance.end(), greater<>());
	int sum = 0;
	for (int i = 0; i < n-1; i++)
	{
		sum += distance[i];
	}
	int ans = 0;

	for(int i=0; i<k-1; i++)
	{
		ans += distance[i];
	}

	cout << sum-ans;

}