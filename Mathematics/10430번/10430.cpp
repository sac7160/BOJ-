//
//  main.cpp
//  BOJ
//
//  Created by Changhyeon Park on 2021/10/28.
//
//10430번

#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    
    cout << (a+b)%c << endl;
    cout << ((a%c) + (b%c))%c << endl;
    cout << (a*b)%c <<endl;
    cout << ((a%c)*(b%c))%c << endl;
    
    return 0;
}
