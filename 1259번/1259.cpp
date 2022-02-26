//
//  main.cpp
//  BOJ
//
//  Created by Changhyeon Park on 2021/10/28.
//
//1259
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string enter;
    
    while(cin>>enter)
    {
        bool check = true;
        if(enter == "0") break;
        for(int i=0; i<enter.size()/2; i++)
        {
            if(enter[i]!= enter[enter.size()-i-1])
            {
                cout << "no" << endl;
                check = false;
                break;
            }
        }
        if(check) cout << "yes" << endl;
    }
}
