//14235번

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
priority_queue<int> present;
void print( )
{
	if (present.empty()) cout << -1 << '\n';
	else
	{
		cout << present.top() << '\n';
		present.pop();
	}
}

int main()
{
	int n;
	vector<int> nums;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int enter;
		cin >> enter;
		nums.push_back(enter);
		if (enter == 0) continue;
		else
		{
			for (int x = 0; x < enter; x++)
			{
				int j;
				cin >> j;
				nums.push_back(j);
			}
		}
	}

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0) print();
		else
		{
			int j = nums[i];
			for (int x =1; x <= j; x++)
			{
				present.push(nums[i + x ]);
			}
			i = i + j;
		}
	}
}