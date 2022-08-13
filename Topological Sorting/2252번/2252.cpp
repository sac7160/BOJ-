#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >>m;
    
    vector<vector<int>> height;
    
    vector<int> tmp;
    
    for(int i=0; i<=n; i++)
    {
        height.push_back(tmp);
    }
    
    int * indegree = new int[n+1];
    for(int i=1; i<=n; i++) indegree[i] = 0;
    
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin >> a >> b;
        height[a].push_back(b);
        indegree[b]++;
    }
    
    queue<int> q;
    
    for(int i=1; i<=n; i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        
        cout << now << " ";
        
        for(int i=0; i<height[now].size(); i++)
        {
            indegree[height[now][i]]--;
            if(indegree[height[now][i]]==0) q.push(height[now][i]);
        }
        
    }
    
    
    delete[] indegree;
   
}

