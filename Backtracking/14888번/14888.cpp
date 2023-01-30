#include <iostream>
#include <vector>

using namespace std;

vector <int> nums;
vector<int>operators;   //+ - * /

int n,tmp;
int max_result=-1000000000;
int min_result=1000000000;
int cur_operator;

void calculate(int length,int result)
{
    if(length == n)
    {
        if(result > max_result) max_result = result;
        if(result < min_result ) min_result = result;
        return;
    }
    
    for(int i=0; i<4; i++)
    {
        int tmp_sum = result;
        if(operators[i]==0) continue;
        
        cur_operator = i;
        if(cur_operator == 0)
        {
            result = result + nums[length];
        }
        else if(cur_operator == 1)
        {
            result = result - nums[length];
        }
        else if(cur_operator == 2)
        {
            result = result * nums[length];
        }
        else if(cur_operator == 3)
        {
            if(result <0)
            {
                result = -result;
                result = result / nums[length];
                result = -result;
            }
            else
                result = result / nums[length];
        }
        
        operators[i]--;
        calculate(length+1, result);
        operators[i]++;
        result = tmp_sum;
    }
    
}

int main()
{
    cin >> n;
    
    for(int i=0; i<n; i++)
    {
        cin >> tmp;
        nums.push_back(tmp);
    }
    
    for(int i=0; i<4; i++)
    {
        cin >> tmp;
        operators.push_back(tmp);
    }
    calculate(1,nums[0]);
    cout << max_result << '\n' << min_result;
}

