//
//  main.cpp
//  BOJ
//
//  Created by Changhyeon Park on 2021/10/28.
//
// 11399번

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> nums;
    int num;
    
    for(int i=0; i<n; i++)
    {
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    int sum =0;
    
    for(int i=0; i<n; i++)
    {
        sum += nums[i]*(n-i);
    }
    cout << sum;
    return 0;
}

