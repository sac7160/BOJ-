//2475번

#include <iostream>
using namespace std;

int main()
{
    int nums[5];
    int sum = 0;
    for(int i =0; i<5; i++)
    {
        cin >> nums[i];
    }
    for(int i =0; i<5; i++)
    {
        sum += nums[i]*nums[i];
    }
    cout << sum %10;
    return 0;
}
