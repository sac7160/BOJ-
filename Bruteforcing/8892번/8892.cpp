//8892번

#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
bool test(string a,string b)
{
	string tmp;
	bool ans1 = true, ans2 = true;

	tmp = a + b;
	for (int i = 0; i < tmp.length() / 2; i++)
	{
		if (tmp[i] != tmp[tmp.length() - i-1])
		{
			ans1 = false;
			break;
		}
	}
	if (ans1 == true)
	{
		cout << a + b << '\n';
		return true;
	}
	
	tmp = b + a;
	for (int i = 0; i < tmp.length() / 2; i++)
	{
		if (tmp[i] != tmp[tmp.length() - i-1])
		{
			ans2 = false;
			break;
		}
	}
	if (ans2 == true)
	{
		cout << b+a << '\n';
		return true;
	}

	return false;
}

int main()
{
	int t, k;
	string enter;
	vector<string>enters;
	bool last = false;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> enter;
			enters.push_back(enter);
		}

		for (int j = 0; j < k - 1; j++)
		{
			for (int x = j + 1; x < k; x++)
			{
				if (test(enters[j], enters[x]))
				{
					last = true;
					break;
				}
			}
			if (last == true) break;
		}
		if (last == false) cout << 0 << '\n';
		enters.clear();
		last = false;
	}
}
