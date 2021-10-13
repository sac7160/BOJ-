//3009번

#include <iostream>

int main()
{
    using namespace std;
    
    int pos[6];
    
    for(int i=0; i<6; i++)
    {
        cin >> pos[i];
    }
    
    int x=0,y=0;
    
    if(pos[0]==pos[2]) x = pos[4];
    else if(pos[0]==pos[4]) x = pos[2];
    else x = pos[0];
    
    if(pos[1]==pos[3]) y = pos[5];
    else if(pos[1]==pos[5]) y = pos[3];
    else y = pos[1];
    
    cout << x << " " << y;
    return 0;
}
