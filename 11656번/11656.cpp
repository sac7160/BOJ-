//10814번

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	using namespace std;

	string s;
	cin >> s;
	int length = s.length();
	vector<string> tmp;

	for (int i = 0; i < length; i++)
	{
		tmp.push_back( s.substr(i, length - i));
	}
	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < tmp.size(); i++)
	{
		cout << tmp[i] << '\n';
	}
}