#include <iostream>

using namespace std;


long long * a;
long long * tmp;
long long ans = 0;

void mergeSort(int s,int e)
{
    if(e-s < 1) return;
    
    int m = (s + e) / 2;
    mergeSort(s, m);
    mergeSort(m+1, e);
    for(int i = s; i<=e; i++)
    {
        tmp[i] = a[i];
    }
    
    int k = s;
    int index1 = s;
    int index2 = m+1;
    
    while(index1 <= m && index2 <= e)
    {
        if(tmp[index1] > tmp[index2])
        {
            a[k] = tmp[index2];
            ans = ans + index2-k;
            k++;
            index2++;
        }
        else{
            a[k] = tmp[index1];
            k++;
            index1++;
        }
    }
    while(index1<=m)
    {
        a[k] = tmp[index1];
        k++;
        index1++;
    }
    while(index2<=e)
    {
        a[k] = tmp[index2];
        k++;
        index2++;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n;
    cin >> n;
    
    a = new long long[n];
    tmp = new long long[n];
    
   
    
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    
    mergeSort(0, n-1);
    cout << ans;
    
    delete [] a;
    delete [] tmp;
}

