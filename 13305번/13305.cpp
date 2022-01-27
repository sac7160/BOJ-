//13305번

#include <iostream>
#include <vector>

int main()
{
	using namespace std;

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n,enter;
	vector<int>length;
	vector<int>price;

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		cin >> enter;
		length.push_back(enter);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		price.push_back(enter);
	}

	long long min = price[0];
	long long sum = 0;

	for (int i = 1; i < n; i++)
	{
		if (price[i - 1] < min) min = price[i - 1];
		sum += min*length[i-1];
	}
	cout << sum;
}