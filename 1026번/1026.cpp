// 1026번

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int a[50];
    int b[50];
    
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> b[i];
    }
    sort(a,a+n);
    sort(b,b+n,greater<>());
    
    int sum =0;
    for(int i=0; i<n; i++)
    {
        sum += a[i]*b[i];
    }
    cout << sum;
    return 0;
    
}