#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	priority_queue<long long, vector<long long>, greater<long long>> nums;
	while (n--)
	{
		long long a;
		cin >> a;
		nums.push(a);
	}
	while (m--)
	{
		long long a, b;
		a = nums.top();
		nums.pop();
		b = nums.top();
		nums.pop();
		nums.push(a + b);
		nums.push(a + b);
	}
	long long sum = 0;
	while (!nums.empty())
	{
		sum += nums.top();
		nums.pop();
	}
	cout << sum;
	return 0;
}