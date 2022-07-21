//20499번

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string kda;
    cin >> kda;
    
    int k = kda[0] - '0';
    int d = kda[2] - '0';
    int a = kda[4] - '0';
    if(k+a < d || d == 0) cout << "hasu" << endl;
    else cout << "gosu" << endl;
    
    return 0;
}

