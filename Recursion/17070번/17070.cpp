#include <iostream>

using namespace std;

int ans = 0;
int n;
int house[18][18];

//shape 0: 가로 1: 세로 2: 대각선
void recursive(int r, int c, int shape)
{
    if (r == n && c == n) ans++;
    else if (house[r][c] == 1) return;
    else
    {
        if (shape == 0)
        {
            if(house[r][c+1]==0)recursive(r, c + 1, 0);
            if(house[r][c+1]==0&&house[r+1][c]==0&&house[r+1][c+1]==0)recursive(r + 1, c + 1, 2);
        }
        else if (shape == 1)
        {
            if(house[r+1][c]==0)recursive(r + 1, c, 1);
            if (house[r][c + 1] == 0 && house[r + 1][c] == 0 && house[r + 1][c + 1] == 0)recursive(r + 1, c + 1, 2);
        }
        else if (shape == 2)
        {
            if (house[r][c + 1] == 0)recursive(r, c + 1, 0);
            if (house[r + 1][c] == 0)recursive(r + 1, c, 1);
            if (house[r][c + 1] == 0 && house[r + 1][c] == 0 && house[r + 1][c + 1] == 0)recursive(r + 1, c + 1, 2);
        }
        return;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i <= n + 1; i++)
    {
        house[0][i] = 1;
        house[n + 1][i] = 1;
        house[i][0] = 1;
        house[i][n + 1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)cin >> house[i][j];
    }
    recursive(1, 2,0);
    cout << ans;
}
