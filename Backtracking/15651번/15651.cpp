#include <iostream>
#include <vector>

using namespace std;

int n,m;
int num = 1;
vector<int> ans;

void backtracking(int depth)
{
    if(depth == m)
    {
        for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
        cout << '\n';
        return;
    }
    for(int i=1; i<=n; i++)
    {
        ans.push_back(i);
        backtracking(depth+1);
        ans.pop_back();
    }
}

int main()
{
    
    cin >> n >> m;
    backtracking(0);
}
