//
//  main.cpp
//  BOJ
//
//  Created by Changhyeon Park on 2021/10/28.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,m,enter,ans = 3;
    vector<int>nums;
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
    {
        cin >> enter;
        nums.push_back(enter);
    }
    
    for(int x=0; x<n-2; x++)
    {
        for(int y=x+1; y<n-1; y++)
        {
            for(int z=y+1; z<n; z++)
            {
                if(nums[x]+nums[y]+nums[z]>m) continue;
                else if(ans<nums[x]+nums[y]+nums[z]) ans = nums[x]+nums[y]+nums[z];
            }
        }
    }
    cout << ans;
}
