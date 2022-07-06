#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n,m;
    cin >> n;
    int * a = new int[n+1];
    
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        
    }
    
    long long * sum = new long long[n+1];
    
    sum[0] = 0;
    
    for(int i=1; i<=n; i++)
    {
        sum[i] = sum[i-1] + a[i];
    }
    
    cin >> m;
    
    for(int x=0; x<m; x++)
    {
        int i,j;
        cin >> i >> j;
        
        cout << sum[j] - sum[i-1] << '\n';
    }
    
    delete[] sum;
    delete[] a;
}

