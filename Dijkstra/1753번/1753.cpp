#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node
{
public:
    int target;
    int weight;
};
int * mydistance;
struct compare
{
    bool operator()(node a,node b){
        //return mydistance[a.target] > mydistance[b.target];
        return a.weight > b.weight;
        
    }
};

priority_queue<node,vector<node>,compare> q;



int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<node>> route;
    vector<node>tmp;
    
    int v,e,k;
    cin >> v >> e >> k;
    
    for(int i=0; i<=v; i++) route.push_back(tmp);
    
    for(int i=0; i<e; i++)
    {
        node enter;
        int a,b,c;
        cin >> a >> b >> c;
        
        enter.target = b;
        enter.weight = c;
        
        route[a].push_back(enter);
    }
    
    
    mydistance = new int[v+1];
    bool * visited = new bool[v+1];
    
    for(int i=1; i<=v; i++)
    {
        mydistance[i] = 999999;
        visited[i] = false;
    }
    
    node a;
    a.target = k;
    a.weight = 0;
    
    q.push(a);
    mydistance[k] = 0;
    
    while(!q.empty())
    {
        node now = q.top();
        q.pop();
        int target = now.target;
        if(visited[target]) continue;
        visited[target] = true;
        
        for(int i =0; i<route[target].size(); i++)
        {
            node tmp = route[target][i];
            int next = tmp.target;
            int value = tmp.weight;
            if(mydistance[next] > mydistance[target]+value)
            {
                mydistance[next] = mydistance[target]+value;
                node b;
                b.target = next;
                b.weight = mydistance[next];
                q.push(b);
            }
        }
    }
    for(int i=1; i<=v; i++)
    {
        if(visited[i]) cout << mydistance[i] << '\n';
        else cout << "INF" << '\n';
    }
    
    delete[] visited;
    delete[] mydistance;
}


