#include <iostream>


int main()
{
    using namespace std;
    int n;
    cin >> n;
    getchar();
    
    
    while(n--)
    {
        string enter;
        getline(cin, enter);
        bool v[26] = {0};
        for(int i=0; enter[i]; i++)
        {
            if('a' <= enter[i] && enter[i]<='z') v[enter[i]-'a'] = true;
            if('A' <= enter[i] && enter[i]<='Z') v[enter[i]-'A'] = true;
        }
    
        int count = 0;
        for(int i=0; i<26; i++) count+=v[i];
        if(count==26) cout<<"pangram"<<'\n';
        else
        {
            cout<<"missing ";
            for(int i=0; i<26; i++) if(!v[i]) cout<<(char)(i+'a');
            cout<<'\n';
        }
    }
}
