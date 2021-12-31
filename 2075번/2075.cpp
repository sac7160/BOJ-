#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	priority_queue<int,vector<int>,greater<>> pq;

	int enter;

	for (int i = 0; i < n*n; i++)
	{
		cin >> enter;

		if (pq.size() < n) pq.push(enter);
		else
		{
			if (pq.top() < enter)
			{
				pq.push(enter);
				pq.pop();
			}
		}
	} 
	cout << pq.top();
	return 0;

}