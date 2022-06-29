#include <iostream>

using namespace std;

int main()
{
     ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    
    long long *nums = new long long[n+1];
    long long *sum = new long long[n+1];
    long long *tmp = new long long[m];
    
    sum[0] = 0;
    
    for(int i=0; i<m; i++) tmp[i] =0;
    
    for(int i=1; i<=n; i++)
    {
        cin >> nums[i];
        sum[i] = sum[i-1] + nums[i];
    }
    
    long long count = 0;
    
    for(int i=1; i<=n; i++)
    {
        int rem = (int)(sum[i]%m);
        tmp[rem]++;
        if (rem==0) count++;
    }
    
    for(int i=0; i<m; i++)
    {
        count += (tmp[i]*(tmp[i]-1)/2);
    }
    cout << count;
    
    delete[] nums;
    delete[] sum;
    delete[] tmp;
}
