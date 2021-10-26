//8958번


#include <iostream>
int main()
{
    using namespace std;
    int num;
    cin >> num;
    char ans[81] = {0,};
    
    for(int i = 0; i< num ;i++)
    {
    
        cin>>ans;
    
    int score = 0;
    int plus = 0;
    
    for(int i = 0; ans[i] != '\0'; i++)
    {
        if(ans[i] == 'O')
        {
            score = score + 1 + plus;
            plus++;
        }
        else if(ans[i] == 'X')
        {
            plus = 0;
        }
    }
   
    cout << score << endl;
    }
  
    return 0;
}
