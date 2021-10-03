//
//  main.cpp
//  10872
//
//  Created by Changhyeon Park on 2021/10/02.
//  재귀함수 사용

#include <iostream>

using namespace std;

void square(int,int,int);
char** answer;

int main(void)
{
    int N;
    cin >>N;
    square(0,0,N);
    for(int i =0; i<N;i++)
    {
        for(int j=0; j<N;j++)
            cout << answer[i][j];
    }
    return 0;
}

void square(int x,int y,int len)
{
    if(len==1)
    {
        answer[x][y] = '*';
        return;
    }
    int newlen = len/3;
    square(x,y,newlen);
    square(x+newlen,y,newlen);
    square(x+2*newlen,y,newlen);
    square(x,y+newlen,newlen);
    square(x+2*newlen,y+newlen,newlen);
    square(x,y+2*newlen,newlen);
    square(x+newlen,y+2*newlen,newlen);
    square(x+2*newlen,y+2*newlen,newlen);
}
