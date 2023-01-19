#include <stack>
#include <iostream>
#include <string>

int main()
{
	using namespace std;

	stack<char> tmp;

	string input;
	cin >> input;
	int ans = 0;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			tmp.push(input[i]);
		}
		else
		{
			if (input[i - 1] == '(')
			{
				tmp.pop();
				ans += tmp.size();
			}
			else
			{
				tmp.pop();
				ans += 1;
			}
		}
	}
	cout << ans;
}
