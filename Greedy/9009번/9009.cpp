//1431번

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

void test(int a)
{
	int f1 = 0;
	int f2 = 1;
	int sum = f1 + f2;
	vector<int>f;
	f.push_back(f1);
	f.push_back(f2);

	while (sum <= a)
	{
		f.push_back(sum);
		sum = f[f.size() - 1] + f[f.size() - 2];
	}

	sort(f.begin(), f.end(), greater<>());

	sum = 0;
	vector<int>ans;

	for(int i=0; i<f.size(); i++)
	{
		if (a >= f[i])
		{
			ans.push_back(f[i]);
			a -= f[i];
			if (a == 0) break;
		}

	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}
int main()
{
	int n,enter;
	vector<int>nums;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		nums.push_back(enter);
	}

	for (int i = 0; i < n; i++)
	{
		test(nums[i]);
		cout << '\n';
	}

}