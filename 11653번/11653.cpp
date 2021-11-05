//11653번

#include <iostream>

using namespace std;

int main()
{
    int x;
    cin >>x;
    
    int divider = 2;
    
    
    while( 1 )
    {
        if(x %divider == 0)
        {
            cout << divider << endl;
            x = x/divider;
            continue;
        }
        divider++;
        if(x == 1) break;
    }
    
    return 0;
}

