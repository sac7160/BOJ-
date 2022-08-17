#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node
{
public:
    int target;
    int value;
};


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int n,m;
    cin >> n >> m;
    
    vector<vector<node>> a;
    vector<vector<node>> reverseA;
    
    vector<node> tmp;
    
    for(int i=0; i<= n; i++)
    {
        a.push_back(tmp);
        reverseA.push_back(tmp);
    }
    
    int *indegree = new int[n+1];
    for(int i=0; i<=n; i++) indegree[i]=0;
    
    for(int i=0; i<m; i++)
    {
        int s,e,w;
        cin >> s >> e >> w;
        
        node tmp;
        tmp.target = e;
        tmp.value = w;
        
        a[s].push_back(tmp);
        
        tmp.target = s;
        reverseA[e].push_back(tmp);
        
        indegree[e]++;
    }
    
    int start,end;
    cin >> start >> end;
    
    queue<int> q;
    
    q.push(start);
    
    int * result = new int[n+1];
    
    for(int i=0; i<=n; i++) result[i] = 0;
    
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i=0; i<a[now].size(); i++)
        {
            indegree[a[now][i].target]--;
            result[a[now][i].target] = max(result[a[now][i].target], result[now]+a[now][i].value);
            if(indegree[a[now][i].target]==0) q.push(a[now][i].target);
        }
    }
    
    int ans = 0;
    
    bool *visited = new bool[n+1];
    for(int i=1; i<=n; i++) visited[i] = false;
    
    q.push(end);
    
    visited[end] = true;
    
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i=0; i<reverseA[now].size(); i++)
        {
            if(result[now] == result[reverseA[now][i].target] + reverseA[now][i].value)
            {
                ans++;
                if(visited[reverseA[now][i].target] == false)
                {
                    visited[reverseA[now][i].target] = true;
                    q.push(reverseA[now][i].target);
                }
            }
        }
    }
    
    cout << result[end] << '\n' << ans;
    
    
    delete[] indegree;
    delete[] result;
    delete[] visited;

}
