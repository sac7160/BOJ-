#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int paint[502][502];
bool visited[502][502];
int max_ans = 0;
int area = 0;
int cnt = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void dfs(int x, int y)
{
    visited[x][y] = true;
    area++;
    for(int i=0; i<4; i++)
    {
        if(visited[x+dx[i]][y+dy[i]]==false && paint[x+dx[i]][y+dy[i]]==1)
        {
            dfs(x+dx[i],y+dy[i]);
        }
    }
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int n,m;
    cin >> n >> m;
    
    for(int i=0;i<=n+1;i++)
    {
        paint[i][0] = 0;
        paint[i][m+1] = 0;
    }
    for(int i=0; i<=m+1; i++)
    {
        paint[0][i] = 0;
        paint[n+1][i] = 0;
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) {
            cin >> paint[i][j];
            visited[i][j] = false;
        }
    }
    
    //초기화
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(!visited[i][j]&& paint[i][j]==1)
            {
                dfs(i, j);
                cnt++;
                if(area>max_ans) max_ans = area;
                area = 0;
            }
        }
    }
    
    cout << cnt << '\n' << max_ans;
    
    
}
