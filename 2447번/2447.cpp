// 재귀함수 

#include <iostream>

using namespace std;

void square(int);

int main(void)
{
    int N;
    cin >>N;
    square(N);
    return 0;
}

void square(int n)
{
    if(n==3)
    {
        for(int i =0; i<3; i++)
            cout<<"*";
        cout << endl << "* *" << endl;
        for(int i =0; i<3; i++)
            cout<<"*"; 
    }
    else
    {
        for(int i=0; i<3; i++)
            square(n/3);
        cout << endl;
        square(n/3);
        for(int i=0; i< n/3; i++) cout <<" ";
        for(int i=0; i<3; i++)
            square(n/3);
    }
}
