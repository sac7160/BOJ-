//2750번

#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >>num;

    int num2[num];
    
    for(int i=0; i<num; i++)
    {
        cin >> num2[i];
        
    }
    
    for(int i=0; i<num; i++)
    {
        int tmp;
        for(int j=i+1; j<num; j++)
        {
            if(num2[i]>num2[j])
            {
                tmp = num2[i];
                num2[i] = num2[j];
                num2[j] = tmp;
            }
        }
        cout << num2[i] << endl;
    }
    
    
}
