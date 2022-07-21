//2630번

#include <iostream>

using namespace std;

int white_cnt = 0;
int blue_cnt = 0;
int nums[129][129]={ 0 };

void check(int width_start,int width_end, int height_start, int height_end)
{
	if (width_end ==width_start )
	{
		if (nums[height_start][width_start] == 0) white_cnt++;
		else blue_cnt++;
		return;
	}
	for (int i = height_start; i <= height_end; i++)
	{
		for (int j = width_start; j <= width_end; j++)
		{
			if (nums[height_start][width_start] != nums[i][j]) {
				check(width_start, (width_start+width_end) / 2, height_start, (height_start+height_end) / 2);
				check((width_start + width_end) / 2 +1, width_end, height_start, (height_start + height_end) / 2);
				check(width_start, (width_start + width_end) / 2, (height_start + height_end) / 2 +1, height_end);
				check((width_start + width_end) / 2 +1, width_end , (height_start + height_end) / 2 +1, height_end);
				return;
			}
		}
	}
	if (nums[height_start][width_start] == 0) white_cnt++;
	else blue_cnt++;
	return;

}

int main()
{
	int n;
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> nums[i][j];
		}
	}

	check(1, n , 1, n );
	cout << white_cnt << '\n' << blue_cnt;

}