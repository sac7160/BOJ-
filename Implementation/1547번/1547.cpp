//1547번

#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int cup1,cup2;
    int ans =1;
    
    for(int i = 0; i< num; i++)
    {
        cin >> cup1 >> cup2;
        if(cup1 == ans) ans = cup2;
        else if(cup2 == ans) ans = cup1;
    }
    
    cout << ans << endl;
    return 0;
}
