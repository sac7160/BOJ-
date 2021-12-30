// 2012번

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int score[500000];
    
    for(int i=0; i<n; i++)
    {
        cin >> score[i];
    }
    
    sort(score, score+n);
    long ans =0;
    for(int i =1; i<=n; i++)
    {
        if(score[i-1] > i ) ans += score[i-1]-i;
        else if( score[i-1] <= i) ans += i - score[i-1];
    }
    cout << ans;
    
    return 0;
    
}

