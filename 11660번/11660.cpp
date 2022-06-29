
#include <iostream>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int n,m;
    cin >> n >> m;
    
    int** nums = new int*[n+1];
    int** sum = new int*[n+1];
    
    for(int i=0; i<n+1; i++)
    {
        nums[i] = new int[n+1];
        sum[i] = new int[n+1];
    }
    
    for(int i=0; i<=n; i++)
    {
        nums[i][0] = sum[i][0] = 0;
    }
    for(int j=0; j<=n; j++)
    {
        nums[0][j] = sum[0][j] = 0;
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> nums[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + nums[i][j];
        }
    }
    
    for(int i=0; i<m; i++)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        cout << sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1] << '\n';
    }
    delete[] nums;
    delete[] sum;
}
