#include <iostream>
#include <vector>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int r,c,q;
    
    cin >> r >> c >> q;
    
    int nums[1001][1001];
    int sum[1001][1001];
    
    for(int i=0; i<=c; i++) sum[0][i] = 0;
    for(int i=0; i<=r; i++) sum[i][0] = 0;
    
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            cin >> nums[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + nums[i][j];
        }
    }
    
    
    for(int i=0; i<q; i++)
    {
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        
        int cnt = (r2-r1+1) * (c2-c1+1);
        
        int ans = sum[r2][c2] - sum[r2][c1-1] - sum[r1-1][c2] + sum[r1-1][c1-1];
        
        
        cout << ans / cnt << '\n';
    }
}

