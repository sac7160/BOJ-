//2775번

#include <iostream>

using namespace std;

int test(int,int);

int main()
{
    int caseNum;
    cin >> caseNum;
    int* a = new int[caseNum];
    int* b = new int[caseNum];
    
    for(int i=0; i<caseNum; i++)
    {
        cin >> a[i] >> b[i];
    }
    for(int i=0; i<caseNum; i++)
    {
        cout << test(a[i],b[i]) << endl;
    }
    
}

int test(int a, int b)
{
    if(b==1) return 1;
    if(a==0) return b;
    else return test(a,b-1) + test(a-1,b);
}
