#include <iostream>
#include <algorithm>

using namespace std;

//같거나 큰 개수 찾아야함-> 전체-작은개수
int binSearch(int* nums,int s,int e, int x)
{
    int start = s;
    int end = e;
    int mid;
    while(start<=end)
    {
        mid = (start + end) /2;
        if(nums[mid] < x)
        {
            start = mid + 1;
        }
        else
            end = mid-1;
    }
    return end;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int high[100000];
    int low[100000];
    
    int n,h;
    cin >> n >> h;
    
    for(int i=0; i<n/2; i++)
    {
        cin >> low[i] >> high[i];
    }
    
    sort(low,low+n/2);
    sort(high,high+n/2);

    
    int min = n - (binSearch(low, 0, n/2-1, 1)+1) - (binSearch(high, 0, n/2-1, h)+1);
    int cnt = 1;
    
    for(int i=2; i<=h; i++)
    {
        int tmp = n/2 - (binSearch(low, 0, n/2-1, i)+1);
        int tmp2 = n/2 - (binSearch(high, 0, n/2-1, h-i+1)+1);
        int ans = tmp + tmp2;
        if(min > ans)
        {
            min =ans;
            cnt = 1;
        }
        else if(min == ans) cnt++;
    }
    cout << min << " " << cnt;
}

