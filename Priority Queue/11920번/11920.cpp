//11920번

#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main()
{
	int n, k;
	cin >> n >> k;
	
	priority_queue<int,vector<int>,greater<>> maxNums;
	vector<int> ans;

	while (n--)
	{
		int enter;
		cin >> enter;
		
		if (maxNums.size() < k) maxNums.push(enter);
		else
		{
			if (maxNums.top() <= enter)
			{
				ans.push_back(maxNums.top());
				maxNums.pop();
				maxNums.push(enter);
			}
			else
			{
				ans.push_back(enter);
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	
	while(!maxNums.empty())
	{
		cout << maxNums.top() << " ";
		maxNums.pop();
	}
}