#include <iostream>

using namespace std;



int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    int * d = new int[n+1];
    
    d[1] = 0;
    for(int i=2; i<=n; i++)
    {
        d[i] = d[i-1]+1;
        if(i%2 ==0) d[i] = min(d[i], d[i/2]+1);
        if(i%3 ==0) d[i] = min(d[i],d[i/3]+1);
    }
    cout << d[n];
    delete[] d;
}
