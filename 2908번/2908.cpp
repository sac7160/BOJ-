//
//  main.cpp
//  BOJ
//
//  Created by Changhyeon Park on 2021/10/28.
//
// 2908번

#include <iostream>
using namespace std;

void print(int);

int main()
{
    int num1,num2;
    
    cin >> num1 >> num2;
    if(num1%10 > num2%10) print(num1);
    else if(num1%10 < num2%10) print(num2);
    else if(num1%100 > num2%100) print(num1);
    else if(num1%100 < num2%100) print(num2);
    else if(num1/100 < num2/100) print(num2);
    else print(num1);
    
    return 0;
    
}

void print(int n)
{
    int a = n/100;
    int b = n/10%10;
    int c = n%10;
    int newNum = c*100 + b*10 + a;
    cout << newNum;
}
