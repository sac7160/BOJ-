//2841번

#include <iostream>
#include <stack>

using namespace std;

int main()
{
	
	int n, p;
	cin >> n >> p;

	stack<int> line[6];

	int enter1, enter2;

	int moves = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> enter1 >> enter2;

		while (!line[enter1 - 1].empty())
		{
			if (line[enter1 - 1].top() > enter2)
			{
				line[enter1 - 1].pop();
				moves++;
			}
			else break;
		}
		if (line[enter1 - 1].empty())
		{
			line[enter1 - 1].push(enter2);
			moves++;
			continue;
		}
		if (line[enter1 - 1].top() == enter2) continue;
		line[enter1 - 1].push(enter2);
		moves++;
	}
	cout << moves;
}