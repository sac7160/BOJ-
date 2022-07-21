//2866번

#include <iostream>
#include <string>

using namespace std;

long long sum[1001][1001];
string table[1001];

int main()
{
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> table[i];
	}
	

	for (int i = 0; i < c; i++)
	{
		int x = 123;
		int tmp=1,a;

		for (int j = r - 1; j >= 0; j--)
		{
			tmp *= x;
			a = tmp * table[j][i];
			sum[j][i] += a;
			if (j != r - 1)
			{
				sum[j][i] += sum[j + 1][i];
			}
		}
	}

	int count = 0;

	for (int i = 1; i < r; i++)
	{
		for (int j = 0; j < c - 1; j++)
		{
			for (int x = j+1; x < c; x++)
			{
				if (sum[i][j] == sum[i][x])
				{
					cout << count << '\n';
					return 0;
				}
			}
		}
		count++;
	}
	cout << count << '\n';
	return 0;
}