#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> tmp;
char a[1001];
char b[1001];
long long** dp;

void getText(int r, int c)
{

    if (r == 0 || c == 0) return;
    if (a[r - 1] == b[c - 1])
    {
        tmp.push(a[r - 1]);
        getText(r - 1, c - 1);
    }
    else
    {
        if (dp[r - 1][c] > dp[r][c - 1]) getText(r - 1, c);
        else getText(r, c - 1);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int a_size, b_size;

    string enter;


    cin >> enter;
    a_size = enter.size();

    for (int i = 0; i < enter.size(); i++)
    {
        a[i] = enter[i];
    }

    cin >> enter;
    b_size = enter.size();

    for (int i = 0; i < enter.size(); i++)
    {
        b[i] = enter[i];
    }

    dp = new long long* [a_size+1];
    for (int i = 0; i <= a_size; i++) dp[i] = new long long[b_size+1];

    for (int i = 0; i <= a_size; i++)
    {
        for (int j = 0; j <= b_size; j++) dp[i][j] = 0;
    }

    for (int i = 1; i <= a_size; i++)
    {
        for (int j = 1; j <= b_size; j++)
        {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1]+1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[a_size][b_size] << '\n';

    getText(a_size, b_size);

    int stack_size = tmp.size();

    for (int i = 0; i < stack_size; i++)
    {
        cout << tmp.top();
        tmp.pop();
    }
}
