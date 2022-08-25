#include <iostream>

using namespace std;



int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    long long **d = new long long*[n+1];
    for(int i=0; i<n+1; i++) d[i] = new long long[2];
    
    d[1][1] = 1;
    d[1][0] = 0;
    
    for(int i=2; i<=n; i++)
    {
        d[i][0] = d[i-1][1] + d[i-1][0];
        d[i][1] = d[i-1][0];
    }
    
    cout << d[n][0]+d[n][1];
    
    delete[]d;
}
