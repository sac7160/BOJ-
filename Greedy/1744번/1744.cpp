#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    priority_queue<int> positive_nums;
    priority_queue<int,vector<int>, greater<int>> negative_nums;
    
    int zero_nums = 0;
    int one_nums = 0;
    
    for(int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        
        if(tmp == 0) zero_nums++;
        else if(tmp == 1) one_nums++;
        else if(tmp<0) negative_nums.push(tmp);
        else positive_nums.push(tmp);
        
    }
    
    int ans = 0;
    
    while(!positive_nums.empty())
    {
        int tmp1;
        int tmp2;
        
        tmp1 = positive_nums.top();
        positive_nums.pop();
        
        if(!positive_nums.empty())
        {
            tmp2 = positive_nums.top();
            positive_nums.pop();
            ans += tmp1 * tmp2;
        }
        else
        {
            ans += tmp1;
        }
    }
    while(!negative_nums.empty())
    {
        int tmp1;
        int tmp2;
        
        tmp1 = negative_nums.top();
        negative_nums.pop();
        
        if(!negative_nums.empty())
        {
            tmp2 = negative_nums.top();
            negative_nums.pop();
            ans += tmp1 * tmp2;
        }
        else
        {
            if(zero_nums==0)
            {
                zero_nums--;
                ans += tmp1;
            }
            else
            {
                zero_nums--;
            }
        }
    }
    cout << ans+one_nums;
}

