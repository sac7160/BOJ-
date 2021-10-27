//
//  main.cpp
//  BOJ
//
//  Created by Changhyeon Park on 2021/10/28.
//
// 4673번

#include <iostream>
void test(int);

int nums[10001] = {0};

int main()
{
    using namespace std;
    for(int x = 1; x<10001; x++)
    {
        test(x);
    }
    for(int x = 0; x<10000; x++)
    {
        if(nums[x] == 0) cout << x+1 << endl;
    }
    
    return 0;
    
}

void test(int n)
{
    int sum = n;
    
   while(1)
   {
       if(n == 0) break;
       sum += n%10;
       n = n/10;
   }
    nums[sum-1] = 1;
}
