#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    if(n==1) return false;
    for(int i=2; i<n; i++)
    {
        if(n%i == 0) return false;
    }
    return true;
}

bool check(int n)
{
    vector<int>num;
    while(n!=0)
    {
        num.push_back(n%10);
        n /= 10;
    }
    for(int i=0; i<num.size()/2; i++)
    {
        if(num[i] != num[num.size()-i-1]) return false;
    }
    return true;
}

int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    
    while(1)
    {
        
        if(check(n) && isPrime(n))
        {
            cout << n;
            return 0;
        }
        n++;
    }
}
