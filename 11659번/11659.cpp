
#include <iostream>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    int nums[100001];
    int sum[100001];
    
    sum[0] = 0;
    
    for(int i=1; i<=n; i++)
    {
        cin >> nums[i];
        sum[i] = sum[i-1] + nums[i];
    }
    
    for(int x=0; x<m; x++)
    {
        int i,j;
        cin >> i >> j;
        
        cout << sum[j] - sum[i-1] << '\n';
    }
}
