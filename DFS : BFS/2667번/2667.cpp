#include <iostream>
#include <string>
#include <queue>

using namespace std;

int nums[27][27];
bool visited[27][27];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int cnt = 0;
priority_queue<int,vector<int>,greater<>> ans;

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
    
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        string enter;
        cin >> enter;
        
        for(int j=1; j<=n; j++)
        {
            nums[i][j] = stoi(enter.substr(j-1,1));
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) visited[i][j] = false;
    }
    
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dfs(i,j);
            if(cnt!=0)
            {
                ans.push(cnt);
                cnt =0;
            }
        }
    }
    
    int tmp = ans.size();
    
    cout << tmp << '\n';
    
    for(int i=0; i<tmp; i++)
    {
        cout << ans.top() << '\n';
        ans.pop();
    }
    
}
