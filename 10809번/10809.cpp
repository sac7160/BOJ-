//10809번

#include <iostream>

using namespace std;

int main()
{
    char* s = new char[100];
    cin >> s;
    
    int ans[26];
    for(int i = 0; i<26; i++)
    {
        ans[i] = -1;
    }

    for(int i = 0; s[i] != 0; i++)
    {
        if(ans[s[i]-'a'] == -1) ans[s[i]-'a'] = i;
        else continue;
    }
    
    for(int i = 0; i<26; i++)
    {
        cout << ans[i] << ' ';
    }
    delete[] s;
    return 0;
}
