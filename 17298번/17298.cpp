// 17298번

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int nums[1000001];
	stack<int> tmp;
	int ans[1000001];

	int enter;
	for (int i = 0; i < n; i++)    //수 입력하는 반복문
	{
		cin >> enter;
		nums[i] = enter;
	}
	// 뒤에서부터 검사
	for (int i = n - 1; i >= 0; i--)
	{
		while (!tmp.empty()&& tmp.top() <= nums[i])
		{
			tmp.pop();
		}
		if (tmp.empty()) ans[i] = -1;
		else ans[i] = tmp.top();
		tmp.push(nums[i]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
}