//11931번

#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;


int main()
{
	int enter,n;
	vector<int>nums;
	
	cin >> n;
	while (n--)
	{
		cin >> enter;
		nums.push_back(enter);
	}

	sort(nums.begin(), nums.end(), greater<>());
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << '\n';
	}
}