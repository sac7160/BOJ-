//5619번

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int test(int x)
{
	int count = 1;

	while (x / 10 != 0)
	{
		x /= 10;
		count++;
	}
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<>> nums;
	long long n;
	cin >> n;

	for (long long i = 0; i < n; i++)
	{
		int enter;
		cin >> enter;
		nums.push(enter);
	}

	int minNums[4];
	int x[4];
	for (int i = 0; i < 4; i++)
	{
		minNums[i] = nums.top();
		x[i] = test(minNums[i]);
		nums.pop();
		if (n == 3 && i == 2) break;
	}
	
	vector<int>ans;

	int a, b;
	if (n > 3) {
		a = pow(10, x[1]) * minNums[0] + minNums[1];
		b = pow(10, x[0]) * minNums[1] + minNums[0];
		ans.push_back(a); ans.push_back(b);

		a = pow(10, x[2]) * minNums[0] + minNums[2];
		b = pow(10, x[0]) * minNums[2] + minNums[0];
		ans.push_back(a); ans.push_back(b);

		a = pow(10, x[3]) * minNums[0] + minNums[3];
		b = pow(10, x[0]) * minNums[3] + minNums[0];
		ans.push_back(a); ans.push_back(b);

		a = pow(10, x[1]) * minNums[2] + minNums[1];
		b = pow(10, x[2]) * minNums[1] + minNums[2];
		ans.push_back(a); ans.push_back(b);

		a = pow(10, x[1]) * minNums[3] + minNums[1];
		b = pow(10, x[3]) * minNums[1] + minNums[3];
		ans.push_back(a); ans.push_back(b);

		a = pow(10, x[2]) * minNums[3] + minNums[2];
		b = pow(10, x[3]) * minNums[2] + minNums[3];
		ans.push_back(a); ans.push_back(b);
	}
	else
	{
		a = pow(10, x[1]) * minNums[0] + minNums[1];
		b = pow(10, x[0]) * minNums[1] + minNums[0];
		ans.push_back(a); ans.push_back(b);

		a = pow(10, x[2]) * minNums[0] + minNums[2];
		b = pow(10, x[0]) * minNums[2] + minNums[0];
		ans.push_back(a); ans.push_back(b);

		a = pow(10, x[1]) * minNums[2] + minNums[1];
		b = pow(10, x[2]) * minNums[1] + minNums[2];
		ans.push_back(a); ans.push_back(b);
	}
	
	sort(ans.begin(), ans.end());

	cout << ans[2];
}
