#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    string find = "666";
    int tmp;
    
    while(true)
    {
        if(find.find("666")!= string::npos)
        {
            --n;
        }
        if(n==0)
        {
            cout << find;
            break;
        }
        tmp = stoi(find);
        tmp++;
        find = to_string(tmp);
    }
}
