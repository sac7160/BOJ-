#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m;

vector<vector<int>> computers;
int * reliability;
int * visited;
queue<int> q;

void BFS(int node)
{
    q.push(node);
    visited[node] = 1;
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for(int i=0; i<computers[tmp].size(); i++)
        {
            if(visited[computers[tmp][i]] != 1)
            {
                q.push(computers[tmp][i]);
                visited[computers[tmp][i]] = 1;
                reliability[computers[tmp][i]] = reliability[computers[tmp][i]]+1;
            }
        }
        
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    vector<int> tmp;
    reliability = new int[n+1];
    visited = new int[n+1];
    
    for(int i=0; i<=n; i++)
    {
        computers.push_back(tmp);
        visited[i]=reliability[i]=0;
    }
    
    for(int i=1; i<=m; i++)
    {
        int a,b;
        cin >> a >> b;
        computers[a].push_back(b);
    }
    
   for(int x=1; x<=n; x++)
    {
        BFS(x);
        for(int j=1; j<=n; j++)  visited[j] = 0;
    }
    
    int max = reliability[1];
    for(int i=2; i<=n; i++) if(max < reliability[i]) max = reliability[i];
    
    for(int i=1; i<=n; i++) if(reliability[i] == max) cout << i << " ";
   
    delete[] reliability;
    delete[] visited;
}
