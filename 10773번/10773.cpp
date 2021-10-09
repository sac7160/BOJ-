//10773번

#include <stack>
#include <iostream>

using namespace std;

int main()
{
    int k;
    cin >> k;
    stack<int> stack;    //스택 생성
    int num_0 =0;
    int sum = 0;
    
    for(int i = 0; i<k; i++)
    {
        int num;
        cin >> num;
        if(num != 0)
        {
            stack.push(num);
            sum+=num;
        }
        else if(num == 0)
        {
            sum-=stack.top();
            stack.pop();
            num_0++;
        }
    }
    
    cout << sum;
    return 0;
}

