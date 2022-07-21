// 2583번

#include <iostream>
#include <queue>
#include <vector>

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

int m,n,k,cnt=0;
char grid[105][105];
int visited[105][105] = { 0 };
vector<int>areas;

void check()
{
	int area = 0;
	while (!q.empty())
	{
		pos cur = q.front();
		q.pop();
		int x = cur.x, y = cur.y;
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];
			if (visited[nx][ny]) continue;
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			visited[nx][ny] = 1;
			q.push({ nx,ny });
			area++;
		}
	}
	if (area == 0) area++;
	areas.push_back(area);
}
int main()
{
	
	cin >> m >> n >> k;

	int x1, y1, x2, y2;

	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x < x2; x++)
		{
			for (int y = y1; y < y2; y++)
			{
				visited[m-y-1][x] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j])continue;
			else
			{
				q.push({ i,j });
				visited[i][j];
				check();
				cnt++;
			}
		}
	}
	sort(areas.begin(), areas.end());

	cout << cnt << '\n';
	for (int i = 0; i < areas.size(); i++)
	{
		cout << areas[i] << " ";
	}
}