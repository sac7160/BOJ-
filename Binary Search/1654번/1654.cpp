#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int k,n;
    cin >> k >> n;
    
    vector<int> ks;
    
    int tmp;
    for(int i=0; i<k; i++)
    {
        cin >> tmp;
        ks.push_back(tmp);
    }

    
    long long start = 0;
    long long end = 100000000000-1;
    long long ans =0;
    
    while(start <= end)
    {
        long long mid = (start+end) / 2;
        
        long sum = 0;
        for(int i=0; i<k; i++) sum += (ks[i]/mid);
        
        if(sum >=n)
        {
            start = mid+1;
            if(mid > ans) ans = mid;
        }
        else
            end = mid-1;
    }
    cout << ans;
}
