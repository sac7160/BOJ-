#include <iostream>

using namespace std;



int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    long long mod = 1000000000;
    
    long long **d = new long long*[n+1];
    for(int i=0; i<n+1; i++) d[i] = new long long[10];
    
    //d[a][b] 길이가 a이고 b로 종료되는 계단의 개수
    
    for(int i=1; i<=9; i++) d[1][i] = 1;
    
    d[1][0] = 0;
    
    for(int i=2; i<=n; i++)
    {
        d[i][0] = d[i-1][1];
        d[i][9] = d[i-1][8];
        for(int j=1; j<=8; j++)
        {
            d[i][j] = (d[i-1][j-1] + d[i-1][j+1])%mod;
        }
    }
    
    long long sum = 0;
    
    for(int i=0;i<=9; i++)
    {
        sum = (sum+d[n][i])%mod;
    }
    
    cout << sum;
    
    delete[]d;
}
