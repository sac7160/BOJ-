#include <iostream>
#include <vector>

using namespace std;

bool arrived = false;
vector <bool> visited;
vector <vector<int>> graph;
vector<int> x;

void DFS(int now, int depth)
{
    if(depth == 5)
    {
        arrived = true;
        return;
    }
    else
    {
        visited[now] = true;
        for(int i=0; i<graph[now].size(); i++)
        {
            if(visited[graph[now][i]] == false ) DFS(graph[now][i], depth+1);
        }
        visited[now] = false;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    
    for(int i =0; i<n; i++) {
        graph.push_back(x);
        visited.push_back(false);
    }
    
    for(int i=0; i<m; i++)
    {
        int tmp,tmp2;
        cin >> tmp >> tmp2;
        graph[tmp].push_back(tmp2);
        graph[tmp2].push_back(tmp);
    }
    
    for(int i=0; i<n; i++)
    {
        DFS(i,1);
        if(arrived)break;
    }
    if(arrived) cout << 1;
    else cout << 0;
}

