//1264번

#include <iostream>
#include <string>

using namespace std;

bool test(char);

int main()
{
    string x;
    getline(cin, x);
    while(x !="#")
    {
        int count =0;
        for(int i=0; i< x.length(); i++)
        {
            if(test(x[i])) count++;
        }
        cout << count << endl;
        
        getline(cin,x);
    }
}

bool test(char x)
{
    if(x == 'a') return true;
    if(x == 'e') return true;
    if(x == 'i') return true;
    if(x == 'o') return true;
    if(x == 'u') return true;
    if(x == 'A') return true;
    if(x == 'E') return true;
    if(x == 'I') return true;
    if(x == 'O') return true;
    if(x == 'U') return true;
    else
        return false;
}