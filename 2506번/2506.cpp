//2506번

#include <iostream>

using namespace std;

int main()
{
    int q = 0;
    int plus =0;
    int score = 0;
    
    cin >> q;
    for (int i=0; i<q; i++)
    {
        int a;
        cin >> a;
        if(a==0) plus = 0;
        else
        {
            plus++;
        }
        score += plus;
    }
    
    cout << score;
    return 0;
}
