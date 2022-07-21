// 3986번

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >>n;
    int count = 0;
    string enter;
    stack<char> test;
    
    while(n--)
    {
        cin >> enter;
        test.push(enter[0]);
        
        for(int i=1; i<enter.size(); i++)
        {
            if(test.empty())
            {
                test.push(enter[i]);
                continue;
            }
            if(test.top() != enter[i]) test.push(enter[i]);
            else if(test.top() == enter[i]) test.pop();
        }
        if(test.empty()) count++;
        while(!test.empty()) test.pop();
    }
    
    cout << count;
    return 0;
}


