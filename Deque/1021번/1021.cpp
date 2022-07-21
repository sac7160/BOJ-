#include <iostream>
#include <vector>
#include <queue>

using namespace std;
deque<int> nums;

bool checkBack(int x)
{
	int idx;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == x)
		{
			idx = i;
			break;
		}
	}
	if (nums.size() / 2 < idx ) return true;
	else return false;
}

int main()
{
	
	int n, m,enter;
	int count = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) nums.push_back(i);
	for (int i = 0; i < m; i++)
	{
		cin >> enter;
		if (checkBack(enter))
		{
			while (nums.front() != enter)
			{
				int tmp;
				tmp = nums.back();
				nums.pop_back();
				nums.push_front(tmp);
				count++;
			}
		}
		else if(!checkBack(enter))
		{
			while (nums.front() != enter)
			{
				int tmp;
				tmp = nums.front();
				nums.pop_front();
				nums.push_back(tmp);
				count++;
			}
		}
		nums.pop_front();
	}
	cout << count;
}