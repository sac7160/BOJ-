//1874번
// 오름차순

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int max = 1;
	int enterNum = 0;
	stack<int> nums;
	vector<int> enterNums;
	vector<char>print;
	nums.push(0);

	for (int i = 0; i < n; i++)
	{
		cin >> enterNum;
		enterNums.push_back(enterNum);
	}

	for (int i = 0; i < n; i++)
	{
		while (enterNums[i] > nums.top())
		{
			nums.push(max);
			print.push_back('+');
			max++;
		}
		if (enterNums[i] < nums.top())
		{
			cout << "NO";
			return 0;
		}
		if (enterNums[i] = nums.top())
		{
			print.push_back('-');
			nums.pop();
		}
		
	}
	for (int i = 0; i < print.size(); i++)
	{
		char ans = print[i];
		cout << ans << '\n';
	}
}