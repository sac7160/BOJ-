#include <iostream>
#include <math.h>

using namespace std;

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    long long *x = new long long[n+1];
    long long *y = new long long[n+1];
    
    for(int i=0; i<n; i++)
    {
        cin >> x[i] >> y[i];
    }
    x[n] = x[0];
    y[n] = y[0];
    
    double ans = 0;
    
    for(int i=0; i<n; i++)
    {
        ans += (x[i]*y[i+1]) - (x[i+1]*y[i]);
    }
    
    if(ans<0) ans = -ans;
    ans = ans/2;

    printf("%.1lf", ans);
    
    delete[] x;
    delete[] y;
}


