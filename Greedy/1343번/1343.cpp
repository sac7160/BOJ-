#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string board;
    cin >> board;
    char* ans = new char[50];
    int count = 0;
    int size =0;
    
    for(int i=0; i<board.size();i++)
    {
        if(board[i] == '.')
        {
            count =0;
            ans[size++] = '.';
        }
        else count++;
    
        if(count%2 == 0 && count!=0)
        {
            ans[size++] = 'B';
            ans[size++] = 'B';
        }
        else if(count %2 == 1 && board[i+1] =='.')
        {
            cout << -1;
            return 0;
        }
        else if (count %2 ==1 && i+1 == board.size())
        {
            cout << -1;
            return 0;
        }
        
    }
    
    // A인지 B인지 검사
    count = 0;
    for(int i =0; i<size; i++)
    {
        
        if(ans[i] == '.'){ count = 0;}
        else count++;
        if(count %4 == 0 && count != 0)
        {
            ans[i] = 'A';
            ans[i-1] = 'A';
            ans[i-2] = 'A';
            ans[i-3] = 'A';
        }
        
    }
    
    for(int i =0; i<size; i++)
    {
        cout << ans[i];
    }
    delete [] ans;
    return 0;
}

