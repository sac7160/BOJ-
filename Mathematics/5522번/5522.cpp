//5522번

#include <iostream>

using namespace std;

int main()
{
    int nums[5];
    int sum =0;
    for(int i=0; i<5; i++)
    {
        cin >>nums[i];
        sum += nums[i];
    }
    cout << sum;
    return 0;

}