#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >>num;
    
    int count =0;
    int tmp = num;
    for(;tmp>0; tmp=tmp/10)
    {
        count++;
    }
    int num2[count];
    for(int i=count; i>0; i--)
    {
        num2[i-1] = num%10;
        num= num/10;
    }
    
    for(int i=0; i<count; i++)
    {
        int tmp;
        for(int j=i+1; j<count; j++)
        {
            if(num2[i]<num2[j])
            {
                tmp = num2[i];
                num2[i] = num2[j];
                num2[j] = tmp;
            }
        }
        cout << num2[i];
    }
    
    
}
