#include <iostream>

using namespace std;

int main()
{
    int score[5];
    for(int i=0; i< 5; i++)
    {
        cin >> score[i];
    }
    int sum = 0;
    
    for(int i=0; i< 5; i++)
    {
        if(score[i] < 40)
            sum += 40;
        else 
            sum += score[i];
    }
    cout << sum;
    return 0;
}