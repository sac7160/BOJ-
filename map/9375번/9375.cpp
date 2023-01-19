#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int test_case;
	cin >> test_case;

	int n;
	map<string, int>clothes;

	for (int i = 0; i < test_case; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			string input;
			cin >> input >> input;
			if (clothes.find(input) != clothes.end())
			{
				clothes[input]++;
			}
			else
			{
				clothes.insert({ input, 1 });
			}
		}
		int ans = 1;
		for (auto iter = clothes.begin(); iter != clothes.end(); iter++)
		{
			ans = ans * (iter->second + 1);
		}
		ans--;
		if (n == 0) ans = 0;
		cout << ans << '\n';
		clothes.clear();
	}
}
