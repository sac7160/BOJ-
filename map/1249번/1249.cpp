#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    map<int,char> m_a;
    map<int,char> m_b;
    
    
    int a,b;
    cin >> a >> b;
    
    int tmp;
    for(int i=0; i<a; i++)
    {
        cin >> tmp;
        m_a.insert({tmp,'a'});
    }
    for(int i=0; i<b; i++)
    {
        cin >> tmp;
        m_b.insert({tmp,'b'});
    }
    
    int ans = 0;
    for(auto iter = m_a.begin(); iter != m_a.end(); iter++)
    {
        int x = iter->first;
        if(m_b.find(x) == m_b.end()) {
            ans++;
        }
    }
    for(auto iter = m_b.begin(); iter != m_b.end(); iter++)
    {
        int x = iter->first;
        if(m_a.find(x) == m_a.end()) {
            ans++;
        }
    }
    cout << ans;
}
