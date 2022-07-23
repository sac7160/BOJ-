#include <iostream>

using namespace std;

int nums[52][52];
bool visited[52][52];

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {1,1,0,-1,-1,-1,0,1};

int cnt = 0;
int ans = 0;

void dfs(int x, int y)
{
    if(visited[x][y] == true || nums[x][y] ==0) return;
    
    visited[x][y] = true;
    cnt++;
    
    for(int i=0; i<8; i++)
    {
        dfs(x+dx[i],y+dy[i]);
    }
    
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int w,h;
    cin >> w >> h;
    
    while(!(w==0 && h==0))
    {
        for(int i=1; i<=h; i++)
        {
            for(int j=1; j<=w; j++)
            {
                cin >> nums[i][j];
            }
        }
        for(int a =1; a<=h; a++ )
        {
            for(int b = 1; b<=w; b++)
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
        
        for(int a =1; a<=h; a++ )
        {
            for(int b = 1; b<=w; b++)
            {
                visited[a][b] = false;
                nums[a][b] = 0;
            }
        }
        cnt = 0;
        ans = 0;
        cin >> w >> h ;
    }
}
