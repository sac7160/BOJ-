#include <iostream>
#include <queue>

using namespace std;

int nums[102][102];
bool visited[102][102];

int dx[8] = {0,1,0,-1};
int dy[8] = {1,0,-1,0};

int cnt = 0;
int ans = 0;

void dfs(int x, int y, int h)
{
    if(visited[x][y] == true || nums[x][y] <=h) return;
    
    visited[x][y] = true;
    cnt++;
    
    for(int i=0; i<4; i++)
    {
        dfs(x+dx[i],y+dy[i],h);
    }
    
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) cin >> nums[i][j];
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) visited[i][j] = false;
    }
    
    priority_queue<int> max;
    
    for(int x =1; x<=100; x++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dfs(i,j,x);
                if(cnt!=0)
                {
                    ans++;
                    cnt = 0;
                }
            }
        }
        max.push(ans);
        ans = 0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++) visited[i][j] = false;
        }
        
    }
    
    cout << max.top();
}
