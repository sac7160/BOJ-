#include <iostream>
#include <algorithm>

using namespace std;

class nums
{
public:
    int num;
    int index;
    
};

bool compare(nums num1,nums num2){return num1.num < num2.num;};

int main()
{
    cin.tie(NULL);
        ios::sync_with_stdio(false);
    int n;
    cin >> n;
    
    nums* a = new nums[n];
    nums* sortedA = new nums[n];
    
    for(int i=0; i<n; i++)
    {
        nums tmp;
        cin >> tmp.num;
        tmp.index = i;
        
        a[i] = tmp;
        sortedA[i] = a[i];
    }
    
    sort(sortedA,sortedA+n,compare);
    
    int max = 0;
    
    for(int i=0; i<n; i++)
    {
        if( sortedA[i].index - i > max) {max = sortedA[i].index - i ;}
    }
    cout << max+1;
    
    delete[] a;
    delete[] sortedA;
}

