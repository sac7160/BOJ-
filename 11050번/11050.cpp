//
//  main.cpp
//  BOJ
//
//  Created by Changhyeon Park on 2021/10/28.
//
//11050

#include <iostream>

using namespace std;

int factorial(int n)
{
    int ans = 1;
    while(n)
    {
        ans *= n;
        n--;
    }
    return ans;
}

int main()
{
    int n,k,ans;
    cin >> n >> k;
    ans = factorial(n)/factorial(n-k)/factorial(k);
    cout << ans;
}
