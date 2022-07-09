#include <iostream>

using namespace std;

int n;

bool isPrime(int number)
{
    for(int i=2; i<=number/2; i++)
    {
        if(number%i == 0) return false;
    }
    return true;
}

void DFS(int number, int digit)
{
    if(digit == n)
    {
        if(isPrime(number)) cout << number << '\n';
        return;
    }
    if(isPrime(number))
    {
        number = 10*number;
        DFS(number+1,digit+1);
        DFS(number+3,digit+1);
        DFS(number+5,digit+1);
        DFS(number+7,digit+1);
        DFS(number+9,digit+1);
    }
    else return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    DFS(2,1);
    DFS(3,1);
    DFS(5,1);
    DFS(7,1);
}

