#include <iostream>
#include <cmath>

using namespace std;

int cnt = 0;

void hanoi(int num, int start, int mid, int end)
{
    if (num == 1) {
        cout << start << " " << end << '\n';
    }
    else
    {
        hanoi(num - 1, start, end, mid);
        cout << start << " " << end << '\n';
        hanoi(num - 1, mid, start, end);
        
    }
}

int main()
{
    int n;
    cin >> n;

    cout << (int)(pow(2, n)) - 1<<'\n';
    hanoi(n, 1, 2, 3);
    
    
}
