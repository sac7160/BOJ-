//11497번

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
vector<int>last;

void test()
{
	int n,enter;
	cin >> n;
	vector<int>nums;
	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		nums.push_back(enter);
	}
	sort(nums.begin(), nums.end(), greater<>());
	vector<int>ans;

	for(int i=1; i<=n; i++)
	{
		if (i % 2 == 1) ans.push_back(nums[i - 1]);
		else if (i % 2 == 0) ans.insert(ans.begin(), nums[i - 1]);
	}

	vector<int>distance;

	for (int i = 1; i < n; i++)
	{
		int tmp = ans[i] - ans[i - 1];
		if (tmp < 0) tmp = -tmp;
		distance.push_back(tmp);
	}
	int tmp = ans[n - 1] - ans[0];
	if (tmp < 0) tmp = -tmp;
	distance.push_back(tmp);

	sort(distance.begin(), distance.end(), greater<>());
	last.push_back(distance[0]);
}

int main()
{
	int t;
	cin >> t;
	for(int i=0; i<t; i++)
	{
		test();
	}

	for (int i = 0; i < t; i++)
	{
		cout << last[i] << "\n";
	}
}

