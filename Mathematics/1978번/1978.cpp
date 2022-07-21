//
//  main.cpp
//  BOJ
//
//  Created by Changhyeon Park on 2021/10/28.
//
//1978번

#include <iostream>

using namespace std;

void test(int);
static int ans = 0;

int main()
{
    
    
    int x;
    cin >> x;
    int *nums = new int[x];
    
    for(int i = 0; i<x; i++)
    {
        cin >> nums[i];
    }
    for(int i = 0; i<x; i++)
    {
        test(nums[i]);
    }
    cout << ans;
    return 0;
}

void test(int n)
{
    int modifier = n-1;
    if(n == 1) {return;}
    else if(n == 2) {ans++; return;}
    while(1)
    {
        if(modifier == 1) {ans++; return;}
        else if(n%modifier == 0) { return;}
        else modifier--;
    }
}
