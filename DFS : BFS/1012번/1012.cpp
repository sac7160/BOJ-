#include <iostream>
#include <string>
#include <queue>

using namespace std;

int nums[52][52];
bool visited[52][52];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int cnt = 0;
int ans = 0;

void dfs(int x, int y)
{
    if(visited[x][y] == true || nums[x][y] ==0) return;
    
    visited[x][y] = true;
    cnt++;
    
    for(int i=0; i<4; i++)
    {
        dfs(x+dx[i],y+dy[i]);
    }
    
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    int n,m,k;
    
    for(int i=0; i<t;i++)
    {
        cin >> m >> n >> k;
        for(int j=0; j<k; j++)
        {
            int x,y;
            cin >> x >> y;
            nums[y+1][x+1] = 1;
        }
        for(int a =1; a<=n; a++ )
        {
            for(int b = 1; b<=m; b++)
            {
                dfs(a, b);
                if(cnt!=0)
                {
                    ans++;
                    cnt = 0;
                }
            }
        }
        cout << ans << endl;
        
        for(int a =1; a<=n; a++ )
        {
            for(int b = 1; b<=m; b++)
            {
                visited[a][b] = false;
                nums[a][b] = 0;
            }
        }
        cnt = 0;
        ans = 0;
    }
}
