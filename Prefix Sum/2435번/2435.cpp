#include <iostream>
#include <vector>

using namespace std;

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k;
    
    cin >> n >> k;
    
    vector<int> a;
    vector<int> ans;
    
    a.push_back(0);
    int sum = 0;
    
    for(int i=1; i<=n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
        
        if(i<k)
        {
            sum += tmp;
        }
        else if(i==k)
        {
            sum += tmp;
            ans.push_back(sum);
        }
        else
        {
            sum +=tmp;
            sum = sum-a[i-k];
            ans.push_back(sum);
        }
    }
    
    int max = ans[0];
    for(int i=0; i<ans.size(); i++) if(max < ans[i]) max = ans[i];
    
    cout << max;
    
}
