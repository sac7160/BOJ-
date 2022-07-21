//
//  main.cpp
//  10872
//
//  Created by Changhyeon Park on 2021/10/02.
//  재귀함수 사용

#include <iostream>
int fac(int);

int main() {
    using namespace std;
    
    int N;
    cin >> N;
    cout << fac(N);
    
    return 0;
}

int fac(int n)
{
    if(n == 0)
        return 1;
    return n * fac(n-1);
}
