//11728번

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, enter;
	cin >> n >> m;
	vector<int> nums;

	for (int i = 0; i < n + m; i++)
	{
		cin >> enter;
		nums.push_back(enter);
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < n + m; i++)
	{
		cout << nums[i] << " ";
	}
}