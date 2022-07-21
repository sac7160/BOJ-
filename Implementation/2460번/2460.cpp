//2460번

#include <iostream>

using namespace std;

int main()
{
    int plus,minus;
    int nums = 0;
    int max = nums;
    
    for(int i =0; i<10; i++)
    {
        cin >> minus >> plus;
        nums = nums + plus - minus;
        if( max < nums ) max = nums;
        
    }
    
    cout << max;
    return 0;
}