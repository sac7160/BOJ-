//2493번

#include <iostream>
#include <stack>

using namespace std;
class pair1
{
public:
	int height;
	int number;
};

int main()
{

	int n;
	pair1* nums = new pair1[500001];
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int enter;
		cin >> nums[i].height;
		nums[i].number = i;
	}

	stack<pair1> tmp;
	int* ans = new int[500001] ;

	for (int i = 0; i < n; i++)
	{
		while (!tmp.empty() && tmp.top().height < nums[i].height)
		{
			tmp.pop();
		}
		if (!tmp.empty()&&tmp.top().height >= nums[i].height)
		{
			ans[i] = tmp.top().number+1;
			tmp.push(nums[i]);
		}
		if (tmp.empty())
		{
			ans[i] = 0;
			tmp.push(nums[i]);
			continue;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}

	delete[] nums;
	delete[] ans;
	return 0;
}