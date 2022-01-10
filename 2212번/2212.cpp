// 2212번

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    using namespace std;
    int n,k,enter;
    int min,max;
    vector<int>location;
    
    cin >> n >> k;
    
    for(int i=0;i<n;i++)
    {
        cin >> enter;
        location.push_back(enter);
    }
    
    sort(location.begin(),location.end());
    
    min = location[0];
    max = location[n-1];
    
    vector<int>distance;
    
    for(int i=1; i<n; i++)
    {
        distance.push_back(location[i]-location[i-1]);
    }
    
    sort(distance.begin(),distance.end(),greater<>());
    
    int sum =0;
    
    if(n < k)
    {
        cout << 0;
        return 0;
    }
    
    for(int i = 0; i<k-1; i++)
    {
        sum += distance[i];
    }
    
    cout << max-min - sum;
}
