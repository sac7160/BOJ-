#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n,k;
    queue<int>queue1;
    cin >> n >> k;
    
    for(int i=1; i<=n; i++)
    {
        queue1.push(i);
    }
    cout << '<';
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<k; j++)
        {
            queue1.push(queue1.front());
            queue1.pop();
        }
        if(i<n-1)cout << queue1.front() << ", ";
        if(i==n-1)cout << queue1.front();
        queue1.pop();
    }
    cout << '>';
    
    return 0;
}
