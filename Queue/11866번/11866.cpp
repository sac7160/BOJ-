//11866번

#include <queue>
#include <iostream>

using namespace std;

int main()
{
    queue<int> nums;
    queue<int> ansNums;
    int n,k;
    
    cin >> n >> k;
    for(int i =1; i<=n; i++)
    {
        nums.push(i);
    }
    
    for(int j=0; j<n; j++)
    {
        for(int i =0; i<k-1; i++)
        {
            nums.push(nums.front());
            nums.pop();
        }
        ansNums.push(nums.front());
        nums.pop();
    }
    
    cout << "<";
    for(int i=0; i<n-1; i++)
    {
        cout << ansNums.front() << ", ";
        ansNums.pop();
    }
    cout << ansNums.front() << '>';
    
    return 0;
}
