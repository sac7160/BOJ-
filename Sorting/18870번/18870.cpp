//18870번

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	
	using namespace std;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int>tmp;
	vector<int>firstArray;

	for (int i = 0; i < n; i++)
	{
		int enter;
		cin >> enter;
		tmp.push_back(enter);
		firstArray.push_back(enter);
	}

	sort(tmp.begin(), tmp.end());
	vector<int>ans;
	ans.push_back(tmp[0]);

	for (int i = 0; i < tmp.size()-1; i++)
	{
		if (tmp[i] == tmp[i + 1]) continue;
		else
		{
			ans.push_back(tmp[i + 1]);
		}
	}

	//ans에 같은수빼고 정렬, fisrtArray에 초기 정렬

	for (int i = 0; i < firstArray.size(); i++)
	{
		int test = firstArray[i];
	
		cout << lower_bound(ans.begin(), ans.end(), test) - ans.begin() << " ";
		
	}

}