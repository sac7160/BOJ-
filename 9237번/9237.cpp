// 9237번

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int nums[100000];
    
    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }
    
    sort(nums, nums+n,greater<>());
    
    for(int i=0; i<n; i++)
    {
        nums[i] = nums[i] + i + 1;
    }
    
    int max = nums[0];
    
    for(int i=1; i<n; i++)
    {
        if(nums[i]>max) max = nums[i];
    }
    
    cout << max +1;
    
    
    return 0;
    
}
