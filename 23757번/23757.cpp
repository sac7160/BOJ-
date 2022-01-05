#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> expectation;
	priority_queue<int>nums;
	int enter;

	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		nums.push(enter);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> enter;
		expectation.push_back(enter);
	}
	for (int i = 0; i < m; i++)
	{
		if (nums.top() < expectation[i])
		{
			cout << 0;
			return 0;
		}
		else
		{
			int tmp = nums.top() - expectation[i];
			nums.pop();
			nums.push(tmp);
		}
	}
	cout << 1;
}