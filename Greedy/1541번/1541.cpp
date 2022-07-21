#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	string enter;
	cin >> enter;

	istringstream ss(enter);

	vector<string> parsing_minus;
	vector<string> parsing_plus;
	int ans = 0;


	string stringBuffer;

	while (getline(ss, stringBuffer, '-'))
	{
		parsing_minus.push_back(stringBuffer);
	}
	//-기준 parsing

	for (int i = 0; i < parsing_minus.size(); i++)
	{
		istringstream ss2(parsing_minus[i]);
		while (getline(ss2, stringBuffer, '+'))
		{
			parsing_plus.push_back(stringBuffer);
		}

		int tmp = 0;
		for (int j = 0; j < parsing_plus.size(); j++)
		{
			 tmp += stoi(parsing_plus[j]);
		}

		if (i == 0) ans += tmp;
		else ans -= tmp;
		parsing_plus.clear();
	}

	cout << ans;


}