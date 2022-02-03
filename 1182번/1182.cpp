#include <iostream>

using namespace std;
int n,s,arr[25];
int ans = 0, sum = 0;

void solve(int idx)
{
    if(idx == n) return;
    if(sum + arr[idx] == s) ans++;
    solve(idx+1);
    sum+= arr[idx];
    solve(idx+1);
    sum -= arr[idx];
}

int main()
{
    cin >> n>> s;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    solve(0);
    cout << ans;
}
