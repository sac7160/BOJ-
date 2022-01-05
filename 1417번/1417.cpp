//1417번

#include <iostream>
#include <queue>

using namespace std;


int main()
{
	int n;
	int x;
	priority_queue<int> candidates;

	cin >> n;
	cin >> x;

	for (int i = 1; i < n; i++)
	{
		int enter;
		cin >> enter;
		candidates.push(enter);
	}
	int count = 0;

	while (!candidates.empty() && x <= candidates.top())
	{
		int tmp = candidates.top()-1;
		candidates.pop();
		candidates.push(tmp);
		x++;
		count++;
	}
	cout << count;

}