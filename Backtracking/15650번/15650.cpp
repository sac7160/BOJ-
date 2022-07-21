#include <iostream>

using namespace std;
int n,m;
int arr[8];

void solve(int cur, int idx)
{
    if(idx == m+1)
    {
        for(int i=1; i<= m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    if(cur == n+1) return;
    arr[idx] = cur;
    solve(cur+1,idx+1);
    solve(cur+1,idx);
}
int main()
{
    cin >> n>> m;
    solve(1,1);
}
