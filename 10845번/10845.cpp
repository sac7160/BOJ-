#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int n,enter2;
	cin >> n;

	string enter;
	queue<int>nums;

	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		if (enter == "push") {
			cin >> enter2;
			nums.push(enter2);
		}
		else if (enter == "pop")
		{
			if (nums.size() == 0) cout << -1 << '\n';
			else
			{
				cout << nums.front() << '\n';
				nums.pop();
			}
		}
		else if (enter == "size") cout << nums.size() << '\n';
		else if (enter == "empty")
		{
			if (nums.size() == 0) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (enter == "front")
		{
			if (nums.size() == 0) cout << -1 << '\n';
			else
			{
				cout << nums.front() << '\n';
			}
		}
		else if (enter == "back")
		{
			if (nums.size() == 0) cout << -1 << '\n';
			else
			{
				cout << nums.back() << '\n';
			}
		}

	}
}