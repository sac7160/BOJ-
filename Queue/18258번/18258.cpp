#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	string input1;
	int n,input2;
	queue<int> q;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input1;
		if (input1 == "push")
		{
			cin >> input2;
			q.push(input2);
		}
		else if (input1 == "pop")
		{
			if (q.empty()) cout << "-1" << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (input1 == "size")
		{
			cout << q.size() <<'\n';
		}
		else if (input1 == "empty")
		{
			if (q.empty()) cout << "1" << '\n';
			else cout << "0" <<'\n';
		}
		else if (input1 == "front")
		{
			if (q.empty()) cout << "-1" << '\n';
			else cout << q.front() <<'\n';
		}
		else if (input1 == "back")
		{
			if (q.empty()) cout << "-1" << '\n';
			else cout << q.back() <<'\n';
		}
	}
}
