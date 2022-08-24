#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node
{
public:
    int target;
    int value;
    node(int target, int value)
    {
        this->target = target;
        this->value = value;
    }
};

struct compare
{
    bool operator()(node a,node b){
        //return mydistance[a.target] > mydistance[b.target];
        return a.value > b.value;
        
    }
};

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    int city[1001];
    bool visited[1001];
    
    cin >> n >> m;
    
    vector<node> tmp;
    vector<vector<node>> route;
    for(int i=0; i<=n; i++)
    {
        route.push_back(tmp);
        city[i] = 999999;
        visited[i] = false;
    }
    
    for(int i=0; i<m; i++)
    {
        int start,end,weight;
        
        cin >> start >> end >> weight;
        route[start].push_back(node(end,weight));
        
    }
    
    int start_index,end_index;
    cin >> start_index >> end_index;
    
    priority_queue<node,vector<node>,compare> q;
    
    q.push(node(start_index,0));
    city[start_index] = 0;
    while(!q.empty())
    {
        node nowNode = q.top();
        int now = nowNode.target;
        q.pop();
        if(nowNode.value > city[now]) continue;
        if(!visited[now])
        {
            for(int i=0; i<route[now].size(); i++)
            {
                if(!visited[route[now][i].target] && city[route[now][i].target]>city[now]+route[now][i].value)
                {
                    city[route[now][i].target] = city[now]+route[now][i].value;
                    q.push(node(route[now][i].target,city[route[now][i].target]));
                }
            }
        }
    }
    
    cout << city[end_index];

    
}


