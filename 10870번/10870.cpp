//재귀 문제풀이

#include <iostream>


int func(int);

int main(void)
{
    using namespace std;
    int n;
    cin >> n;
    cout << func(n);
    
}

int func(int n)
{
    if(n==0) return 0;
    else if (n == 1) return 1;
    else
     {
         return func(n-1) + func(n-2);
     }
}
