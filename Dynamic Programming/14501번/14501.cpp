#include <iostream>

using namespace std;



int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    int * d = new int[n+2];
    for(int i=0; i<=n+1; i++) d[i] =0;
        
    //d[i] : i번째 날부터 퇴사일 까지 벌 수 있는 최대 수입
    
    int * t = new int[n+1];
    int * p = new int[n+1];
    
    for(int i=1; i<=n; i++)
    {
        cin >> t[i] >> p[i];
    }
    
    for(int i=n; i>0; i--)
    {
        if(i+t[i]>n+1)
        {
            d[i] = d[i+1];
        }
        else
        {
            d[i] = max(d[i+1],p[i]+d[i+t[i]]);
        }
    }
    cout << d[1];
    
    delete[] t;
    delete[] p;
    delete[] d;
}
