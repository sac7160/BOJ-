//4153번

#include <iostream>

using namespace std;

int main()
{
    while(1)
    {
        int nums[3];
        for(int i=0; i<3; i++)
        {
            cin >> nums[i];
        }
        
        if( nums[0] == 0 && nums[1] == 0 && nums[2] == 0) break;
        
        int tmp;
        for(int i = 0; i<3; i++)
        {
            for(int x = i+1; x<3; x++)
            {
                if(nums[i] < nums[x]) {
                    tmp = nums[i];
                    nums[i] = nums[x];
                    nums[x] = tmp;
                }
            }
        }
        if( nums[0]*nums[0] == nums[1]*nums[1] + nums[2]*nums[2]) cout << "right" << endl;
        else cout << "wrong" << endl;
        
    }
    return 0;
}
