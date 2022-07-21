#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n,enter;
	int cnt[10001] = { 0 };

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> enter;
		cnt[enter]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		while (cnt[i])
		{
			cout << i << '\n';
			cnt[i]--;
		}
	}
}