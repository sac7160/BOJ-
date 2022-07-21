//3003번

#include <iostream>

using namespace std;

int main()
{
    int nums[6];
    
    for(int i = 0; i<6 ; i++)
    {
        cin >> nums[i];
    }
    
    cout << 1 - nums[0] << " " << 1 - nums[1] << " " << 2 - nums[2] << " " << 2 - nums[3] << " " << 2 - nums[4] << " " << 8 - nums[5] << endl;
    
    return 0;
}
