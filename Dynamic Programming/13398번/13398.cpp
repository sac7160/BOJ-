#include <iostream>

using namespace std;



int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    cin >> n;
    
    int *a = new int[n];
    int *l = new int[n];
    int *r = new int[n];
    
    for(int i=0; i<n; i++) cin >> a[i];
    
    l[0] = a[0];
    int ans = l[0];
    
    for(int i=1; i<n; i++)
    {
        l[i] = max(a[i],l[i-1]+a[i]);
        ans = max(ans,l[i]);
    }
    
    r[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--)
    {
        r[i] = max(a[i],r[i+1]+a[i]);
    }
    
    for(int i=1; i<n-1; i++)
    {
        int tmp = l[i-1]+r[i+1];
        ans = max(ans,tmp);
    }
    
    cout << ans;
    
    delete[] a;
    delete[] l;
    delete[] r;
    
}
