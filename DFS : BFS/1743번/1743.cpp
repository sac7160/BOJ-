#include <iostream>

using namespace std;

int road[102][102];
bool visited[102][102];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int cnt = 0;

void dfs(int x, int y)
{
    visited[x][y] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if (road[next_x][next_y] == 1 && visited[next_x][next_y] == false)
        {
            dfs(next_x, next_y);
        }
    }
}


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        road[r][c] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) visited[i][j] = false;
    }
    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!visited[i][j] && road[i][j] == 1)
            {
                dfs(i, j);
                if (max < cnt) max = cnt;
                cnt = 0;
            }
        }
    }
    cout << max;

}
