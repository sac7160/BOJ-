//
//  main.cpp
//  BOJ
//
//  Created by Changhyeon Park on 2021/10/28.
//
//7795

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    using namespace std;
    
    int t,n,m,enter;
    int count;
    cin >> t;
    vector<int> a;
    vector<int> b;
    
    for(int i=0; i<t; i++)
    {
        count = 0;
        
        cin >> n >> m;
        while(n--)
        {
            cin >> enter;
            a.push_back(enter);
        }
        while(m--)
        {
            cin >> enter;
            b.push_back(enter);
        }
        sort(a.begin(), a.end()); // 오름차순 정렬
        sort(b.begin(), b.end());
        
        for(int i=0; i<a.size(); i++)
        {
            if(lower_bound(b.begin(),b.end(),a[i]) - b.begin() > b.size())
            {
                count = count + b.size();
                if(b[m-1] == a[i]) count--;
            }
            else
            {
                count = count +(lower_bound(b.begin(),b.end(),a[i]) - b.begin());
            }
        }
        cout << count << '\n';
        a.clear();
        b.clear();
    }
}
