#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    long k,tmp;
    priority_queue<long, vector<long>, greater<long>>q;
    for(int i = 0; i<t; i++)
    {
        long ans = 0;
        long min_1,min_2;
        
        cin >> k;
        for(int j=0; j<k; j++)
        {
            cin >> tmp;
            q.push(tmp);
        }
        
        while(q.size() != 1)
        {
            min_1 = q.top();
            q.pop();
            min_2 = q.top();
            q.pop();
            ans += (min_1 + min_2);
            q.push(min_1 + min_2);
        }
        cout << ans << '\n';
        q.pop();
    }
}
