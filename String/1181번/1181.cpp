//1181번

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string a, string b)
{
	if (a.size() != b.size())
		return a.size() < b.size();
	else
		return a < b;
}


int main()
{
	int n;
	cin >> n;
	vector <string> tmp;
	for (int i = 0; i < n; i++)
	{
		string enter;
		cin >> enter;
		tmp.push_back(enter);
	}

	sort(tmp.begin(), tmp.end(), compare);
	vector <string> ans;
	ans.push_back(tmp[0]);

	for (int i = 0; i < tmp.size()-1; i++)
	{
		if (tmp[i] == tmp[i + 1]) continue; 
		else
		{
			ans.push_back(tmp[i + 1]);
		}
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}
}