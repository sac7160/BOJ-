#include <iostream>
#include <string>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //d[n][l][r] : n개의 빌딩 중 왼쪽l개 오른쪽 r개 보일때 가능한 경우의 수

    long long mod = 1000000007;
    int n, l, r;
    cin >> n >> l >> r;
    
    long long*** d = new long long** [n+1];
    
    for (int i = 0; i < n+1; i++) {
        d[i] = new long long* [l+1];
        for (int j = 0; j < l+1; j++) {
            d[i][j] = new long long[r+1];
        }
    }
    


    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= l; j++)
        {
            for (int x = 0; x <= r; x++)
            {
                d[i][j][x] = 0;
            }
        }
    }

    d[1][1][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            for (int x = 1; x <= r; x++)
            {
                d[i][j][x] = (d[i-1][j][x]*(i-2) + (d[i-1][j][x-1] + d[i-1][j-1][x]))%mod;
            }
        }
    }

    cout << d[n][l][r];

  
}
