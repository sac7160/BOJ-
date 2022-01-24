//1037번
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,enter;
    cin >> n;
    
    vector<int>nums;
    for(int i=0; i<n;i++)
    {
        cin >> enter;
        nums.push_back(enter);
    }
    
    sort(nums.begin(),nums.end());
    cout << nums[0] * nums[n-1];
    
}
