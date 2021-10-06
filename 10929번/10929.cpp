//10929번
#include <iostream>
#include <string.h>

using namespace std;


int stack[10001];
static int sp = 0;

void push(int n){
    stack[sp++] = n;
}

void empty(){
    if(sp == 0)
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
}

void pop(){
    if(sp == 0)
    {
        cout << -1;
    }
    else
    {
        cout << stack[sp-1];
        sp--;
    }
       
}

void size(){
    cout << sp;
}

void top(){
    if(sp != 0)
    {
        cout << stack[sp-1];
    }
    else
        cout << -1;
}

int main(){
    for(int i =0; i<10000; i++) stack[i] =0;
    int N;
    cin >> N;
    
    for(int i=0; i< N; i++)
    {
        string x;
        cin >> x;
        
        if(x == "push")
        {
            int y;
            cin >> y;
            push(y);
        }
        else if (x == "pop") {pop(); cout << endl;}
        else if (x == "size") {size(); cout << endl;}
        else if (x == "empty") {empty(); cout << endl;}
        else if (x == "top") {top(); cout << endl;}
    }
    return 0;
}


