//1297번

#include <iostream>

using namespace std;

int main()
{
    int S[4];
    int T[4];
    int sum_S =0;
    int sum_T=0;
    
    for(int i = 0; i <4; i++)
    {
        cin >> S[i];
        sum_S += S[i];
    }
    for(int i=0; i<4; i++)
    {
        cin >>T[i];
        sum_T += T[i];
    }
    
    if(sum_S >= sum_T) cout << sum_S;
    else cout << sum_T;
    
    return 0;
    
}
