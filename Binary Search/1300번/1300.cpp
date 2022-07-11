#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int n;
    cin >> n;
    int k;
    cin >> k;
    
    long long start = 1;
    long long end = k;
    long long ans = 0;
    
    while(start<=end)
    {
        long long middle = (start+end) /2;
        long long cnt = 0;
        
        for(int i=1; i<=n; i++)
        {
            if(middle/i <= n) cnt +=middle/i;
            else cnt += n;
        }
        if(cnt <k) start = middle+1;
        else
        {
            ans = middle;
            end = middle -1;
        }
    }
    cout << ans;
}

