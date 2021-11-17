//2566번

#include <iostream>
using namespace std;

int main()
{
    int max=0;
    int nums[9][9];
    int x=0;
    int y=0;
    
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cin >> nums[i][j];
            if(nums[i][j] > max)
            {
                max = nums[i][j];
                x = j;
                y = i;
            }
        }
    }
    
    cout << max << endl;
    cout << y+1 << " " << x+1 << endl;
    return 0;
}

