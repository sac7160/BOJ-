//4583번

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	bool test = true;

	string enter;
	cin >> enter;

	while (enter != "#")
	{
		stack<char> ans;
		for (int i = 0; i < enter.length(); i++)
		{
			if (enter[i] == 'b') ans.push('d');
			else if (enter[i] == 'd') ans.push('b');
			else if (enter[i] == 'p') ans.push('q');
			else if (enter[i] == 'q') ans.push('p');
			else if (enter[i] == 'i') ans.push('i');
			else if (enter[i] == 'o') ans.push('o');
			else if (enter[i] == 'v') ans.push('v');
			else if (enter[i] == 'w') ans.push('w');
			else if (enter[i] == 'x') ans.push('x');
			else
			{
				cout << "INVALID";
				test = false;
				break;
			}
		}
		if (test)
		{
			while (!ans.empty())
			{
				cout << ans.top();
				ans.pop();
			}
		}
		else
		{
			while (!ans.empty())
			{
				ans.pop();
			}
		}
		cout << '\n';
		test = true;
		cin >> enter;
	}
}