#include <iostream>
#include <vector>

using namespace std;

int n,m;

bool * visited;
vector<int>arrayList[1001];

void DFS(int v)
{
    if(visited[v]) return;
    visited[v] = true;
    for(int i=0; i<arrayList[v].size(); i++)
    {
        if(visited[arrayList[v][i]] == false) DFS(arrayList[v][i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    int u,v;
    
    cin >> n >> m;
    
    visited = new bool[n+1];
    
    for(int i=1; i<=n; i++)
    {
        visited[i] = false;
    }
    
    
    for(int i=0; i<m; i++)
    {
        cin >> u >> v;
        arrayList[u].push_back(v);
        arrayList[v].push_back(u);
    }
    
    int ans = 0;
    
    for (int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            ans++;
            DFS(i);
        }
    }
    
    cout << ans;
    
    delete [] visited;
    
}

