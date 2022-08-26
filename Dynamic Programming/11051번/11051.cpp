#include <iostream>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int ** dp = new int*[n+1];
    for (int i = 0; i < n + 1; i++) dp[i] = new int[n + 1];

    for (int i = 0; i <= n; i++)
    {
        dp[i][1] = i;
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            dp[i][j] = dp[i][j] % 10007;
        }
    }
    cout << dp[n][k];
   
  
}
