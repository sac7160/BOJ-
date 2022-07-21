#include <iostream>

using namespace std;
char square[51][51];
int ans_WB = 0, ans_BW = 0;
int ans = 64;

char BW[8][8] = {
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B'
};

char WB[8][8] = {
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
};

void cnt_WB(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (WB[i][j] != square[x + i][y + j]) ans_WB++;
		}
	}
}

void cnt_BW(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (BW[i][j] != square[x + i][y + j]) ans_BW++;
		}
	}
}

int main()
{
	
	int n, m;
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> square[i][j];
		}
	}

	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			cnt_BW(i, j);
			cnt_WB(i, j);
			int smaller;
			if (ans_BW < ans_WB) smaller = ans_BW;
			else smaller = ans_WB;
			if (smaller< ans) ans = smaller;
			ans_BW = ans_WB = 0;
		}
	}
	cout << ans;
}