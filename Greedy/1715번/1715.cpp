#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<>> nums;
	for (int i = 0; i < n; i++)
	{
		int enter;
		cin >> enter;
		nums.push(enter);
	}
	int sum =0;
	for (int i = 0; i < n - 1; i++)
	{
		int a,b;
		a = nums.top();
		nums.pop();
		b = nums.top();
		nums.pop();
		sum = sum + a + b;
		nums.push(a + b);
	}
	cout << sum;
}