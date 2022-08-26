#include <iostream>
#include <string>

using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //d[n][l][r] : n개의 수열 수해 후 왼발이 l, 오른발이 r일때 최소 누적 합
;
    int *** dp = new int** [100001];
    
    for (int i = 0; i < 100001; i++) {
        dp[i] = new int* [5];
        for (int j = 0; j < 5; j++) {
            dp[i][j] = new int[5];
        }
    }

    int mp[5][5] = {
        {0,2,2,2,2},
        {2,1,3,4,3},
        {2,3,1,3,4},
        {2,4,3,1,3},
        {2,3,4,3,1}
    };

    int n = 0, s = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 100001; k++) dp[k][i][j] = 100001*4+100;
        }
    }

    dp[0][0][0] = 0;

    while (true)
    {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < 5; i++)
        {
            if (n == i) continue;
            for (int j = 0; j < 5; j++) dp[s][i][n] = min(dp[s - 1][i][j] + mp[j][n], dp[s][i][n]);
        }

        for (int j = 0; j < 5; j++)
        {
            if (n == j) continue;
            for (int i = 0; i < 5; i++) dp[s][n][j] = min(dp[s - 1][i][j] + mp[i][n], dp[s][n][j]);
        }
        s++;
    }
    s--;
    int ans = 999999999;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)ans = min(ans, dp[s][i][j]);
    }
    cout << ans;
  
  
}
