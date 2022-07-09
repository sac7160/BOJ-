#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[100001];
vector<vector<int>> rel;
vector<int>tmp;
int parent[100001];
queue<int> q;



void BFS(int now)
{
    visited[now] = true;
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        visited[tmp] = true;
        for(int i=0; i<rel[tmp].size(); i++)
        {
            if(!visited[rel[tmp][i]])
            {
                visited[rel[tmp][i]] = true;
                q.push(rel[tmp][i]);
                parent[rel[tmp][i]] = tmp;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    
    for(int i=0; i<=n; i++) {
        rel.push_back(tmp);
        visited[i] = false;
    }
    
    for(int i=0; i<n-1; i++)
    {
        int x,y;
        cin >> x >> y;
        rel[x].push_back(y);
        rel[y].push_back(x);
    }
    q.push(1);
    BFS(1);
    
    for(int i = 2; i<=n; i++) cout << parent[i] << '\n';
}

