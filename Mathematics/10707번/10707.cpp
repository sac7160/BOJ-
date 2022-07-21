//10707번

#include <iostream>

using namespace std;

int main()
{
    int A,B,C,D,P;
    int x = 0;
    int y = 0;
    
    cin >> A >> B >> C >> D >> P;
    
    x = A*P;
    if(P<=C) y = B;
    else if(P>C) y = B + (P-C)*D;
    
    if(x > y) cout << y;
    else cout << x;
    return 0;
    
}
