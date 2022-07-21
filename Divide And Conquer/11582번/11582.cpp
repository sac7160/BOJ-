//11582번

#include <iostream>
#include <vector>
#include<algorithm>

int main()
{

	using namespace std;
	int n,enter,k;
	cin >> n;
	vector<int>nums;
	vector<int> ans;

	for(int i=0; i<n; i++)
	{
		cin >> enter;
		nums.push_back(enter);
	}

	cin >> k;
	int index = 0;

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n / k; j++)
		{
			ans.push_back(nums[index]);
			index++;
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		ans.clear();
	}
}