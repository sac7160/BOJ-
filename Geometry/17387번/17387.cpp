#include <iostream>

using namespace std;

int convert(long long x)
{
    if(x<0) return -1;
    else if(x>0) return 1;
    else return 0;
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long x1,x2,x3,x4,y1,y2,y3,y4;
    
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
    long long abc,abd,cda, cdb;
    
  
    abc = (x1*y2 + x2 * y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3);
    abd = (x1*y2 + x2 * y4 + x4*y1) - (x2*y1 + x4*y2 + x1*y4);
    cda = (x3*y4 + x4 * y1 + x1*y3) - (x4*y3 + x1*y4 + x3*y1);
    cdb = (x3*y4 + x4 * y2 + x2*y3) - (x4*y3 + x2*y4 + x3*y2);
    
    abc = convert(abc);
    abd = convert(abd);
    cda = convert(cda);
    cdb = convert(cdb);
    
    
    if(abc*abd ==0 && cda*cdb ==0)
    {
        if(min(x1,x2)<=max(x3,x4) && min(x3,x4) <= max(x1,x2)&&min(y1,y2)<=max(y3,y4) && min(y3,y4) <= max(y1,y2)) cout << 1;
        else cout << 0;
    }
    else if(abc*abd <=0 && cda*cdb <=0) cout << 1;
    else cout << 0;
}


