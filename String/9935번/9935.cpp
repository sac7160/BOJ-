#include <iostream>
#include <string>
#include <stack>

using namespace std;
stack<char> ans;
stack<char> buf;

string input;
string bomb;

void test()
{
    int index = bomb.size()-1;
    
    while(ans.top() == bomb[index] )
    {
        buf.push(ans.top());
        ans.pop();
        if(index == 0)  //폭발
        {
            int size = buf.size();
            for(int i=0; i<size; i++) buf.pop();
            return;
        }
        else if(ans.size() ==0) break;
        index--;
    }
    
    int tmp = buf.size();
    for(int i=0; i<tmp; i++)
    {
        ans.push(buf.top());
        buf.pop();
    }
}

int main()
{
    
    cin >> input >> bomb;
    
    for(int i=0; i<bomb.size(); i++) ans.push(input[i]);
    
    test();
    
    for(int i=bomb.size(); i<input.size(); i++)
    {
        ans.push(input[i]);
        test();
    }
    
    int size = ans.size();
    
    if(size == 0)
    {
        cout << "FRULA";
        return 0;
    }
    for(int i=0 ; i<size; i++)
    {
        buf.push(ans.top());
        ans.pop();
    }
    for(int i=0 ; i<size; i++)
    {
        cout << buf.top();
        buf.pop();
    }
}
/*
 반례
 AABCBABCBABCCABCC
 ABC
 ABBCC
 output : abbacbc
 answer :abbcc
 */


