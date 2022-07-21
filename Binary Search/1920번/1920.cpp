// 1920번

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    vector<int>a_array;
    vector<int>m_array;
    cin>> n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        a_array.push_back(x);
    }
    sort(a_array.begin(), a_array.end());
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int x;
        cin >> x;
        m_array.push_back(x);
    }
    for(int i=0; i<m; i++)
    {
        int m_arrayElement;
        m_arrayElement = m_array[i];
        if(binary_search(a_array.begin(), a_array.end(), m_arrayElement)) cout << "1" << '\n';
        else cout << '0' << '\n';
    }
    return 0;
}
