// 10026번

#include <iostream>
#include <queue>

using namespace std;


class pos
{
public:
	int x;
	int y;
};

queue<pos>q;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, ans=0, ans2=0;
char grid[105][105];
int visited[105][105] = { 0 };

void check()
{
	while (!q.empty())
	{
		pos cur = q.front();
		q.pop();
		int x = cur.x, y = cur.y;
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];
			if (visited[nx][ny]) continue;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (grid[nx][ny] != grid[x][y]) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	
}
int main()
{
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}

	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j])continue;
			else
			{
				q.push({ i,j });
				visited[i][j];
				check();
				ans++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 'R') grid[i][j] = 'G';
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j])continue;
			else
			{
				q.push({ i,j });
				visited[i][j];
				check();
				ans2++;
			}
		}
	}
	cout << ans << " " << ans2;
}