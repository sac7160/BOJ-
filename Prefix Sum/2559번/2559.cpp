#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n,k;
    cin >> n >> k;
    
    int * a = new int[n+1];
    int * sum = new int[n+1];
    
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    
    sum[k]= 0;
    for(int i=1; i<=k; i++) sum[k]+= a[i];
    
    int max = sum[k];
    
    for(int i = k+1; i<=n;i++)
    {
        sum[i] = sum[i-1] - a[i-k] + a[i];
        if(sum[i] > max) max = sum[i];
    }
    cout << max;
}

