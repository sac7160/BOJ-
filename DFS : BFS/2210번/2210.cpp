#include <iostream>
#include <vector>

using namespace std;

int nums[7][7];
int ans = 0;
bool sum_check[1000000];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void dfs(int x, int y, int sum, int cnt)
{
    if(cnt == 6)
    {
        if(sum_check[sum] == false)
        {
            sum_check[sum] = true;
            ans++;
        }
        return;
    }
    
    for(int i=0; i<4; i++)
    {
        if(nums[x+dx[i]][y+dy[i]] !=-1)
        dfs(x+dx[i], y+dy[i], sum*10+nums[x+dx[i]][y+dy[i]], cnt+1);
    }
    
    
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    for(int i=0; i<7; i++)
    {
        nums[0][i] = -1;
        nums[i][0] = -1;
        nums[6][i] = -1;
        nums[i][6] = -1;
    }
    
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=5; j++) cin >> nums[i][j];
    }
    
    for(int i=1; i<=5; i++)
    {
        for(int j=1; j<=5; j++) dfs(i,j,0,0);
    }

    cout << ans;
}
