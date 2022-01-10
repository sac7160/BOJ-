//10867번

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n,enter;
	cin >> n;
	vector<int> nums;

	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		nums.push_back(enter);
	}

	sort(nums.begin(), nums.end());
	vector<int>ans;
	ans.push_back(nums[0]);

	for (int i = 1; i < n; i++)
	{
		if (ans.back() != nums[i]) ans.push_back(nums[i]);
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	
}