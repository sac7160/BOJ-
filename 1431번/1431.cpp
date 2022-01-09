//1431번

#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

bool compare(string a,string b)
{
	if (a.length() != b.length())
	{
		return a.length() < b.length();
	}
	else if (a.length() == b.length())
	{
		int a_sum = 0;
		int b_sum = 0;
		for (int i = 0; i < a.length(); i++)
		{
			if (a[i] <='9') a_sum += a[i]-'0';
		}
		for (int i = 0; i < b.length(); i++)
		{
			if (b[i] <='9' ) b_sum += b[i]-'0';
		}
		if (a_sum != b_sum) return a_sum < b_sum;
		else return a < b;
	}
}
int main()
{
	int n;
	vector<string>numbers;
	string enter;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		numbers.push_back(enter);
	}
	sort(numbers.begin(), numbers.end(), compare);
	for (int i = 0; i < n; i++)
	{
		cout << numbers[i] << '\n';
	}
}