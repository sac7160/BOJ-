//16916번

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char* p = new char[1000001];
    char* s = new char[1000001];
   

    cin >> s >> p;

    char* ptr = strstr(s,p);
    if (ptr == NULL) cout << 0;
    else cout << 1;

    delete[] s;
    delete[] p;

}