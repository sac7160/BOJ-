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
    
    vector<vector<int>> builds;
    vector<int> tmp;
    
    for(int i=0; i<=n; i++) builds.push_back(tmp);
    
    int *indegree = new int[n+1];
    int *self = new int[n+1];
    
    for(int i=1; i<=n; i++) indegree[i] = 0;
    
    for(int i=1; i<=n; i++)
    {
        cin >> self[i];
        int enter;
        cin >> enter;
        while(enter!=-1)
        {
            indegree[i]++;
            builds[enter].push_back(i);
            cin >> enter;
        }
    }
    
    int *ans = new int[n+1];
    
    queue<int> q;
    
    for(int i=1; i<=n; i++) if(indegree[i]==0) q.push(i);
    
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i=0; i<builds[now].size(); i++)
        {
            indegree[builds[now][i]]--;
            ans[builds[now][i]] = max(ans[builds[now][i]], ans[now]+self[now]);
            
            if(indegree[builds[now][i]] ==0) q.push(builds[now][i]);
        }
    }
    
    for(int i=1; i<=n; i++) cout << ans[i] + self[i]  << '\n';
    
    
    delete[] ans;
    delete[] indegree;
    delete[] self;
}

