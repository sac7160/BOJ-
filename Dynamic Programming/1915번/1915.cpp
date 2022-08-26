#include <iostream>
#include <string>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    long long **dp = new long long*[n];
    for (int i = 0; i < n; i++) dp[i] = new long long[m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)dp[i][j] = 0;
    }

    long long max = 0;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
       
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = tmp[j]-'0';
           
            if (dp[i][j] == 1 && j > 0 && i > 0)
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            if (max < dp[i][j]) max = dp[i][j];
        }
    }
    cout << max * max;

  
}
