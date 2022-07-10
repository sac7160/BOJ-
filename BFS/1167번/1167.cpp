#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Edge
{
public:
    int e;
    int weight;
};

vector<vector<Edge>> ArrayList;
vector<Edge> tmp;
bool *visited;
int *dist;

void BFS(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for(int i =0; i<ArrayList[tmp].size(); i++)
        {
            if(visited[ArrayList[tmp][i].e] == false)
            {
                dist[ArrayList[tmp][i].e] = dist[tmp] + ArrayList[tmp][i].weight;
                visited[ArrayList[tmp][i].e] = true;
                q.push(ArrayList[tmp][i].e);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v;
    cin >> v;
    
    dist = new int[100001];
    visited = new bool[100001];
    
    for(int i=0; i<=v; i++) ArrayList.push_back(tmp);
    
    for(int i=0; i<v; i++)      //인접리스트 저장
    {
        int enter;
        cin >> enter;
        while(true)
        {
            int enter2;
            cin >> enter2;
            if(enter2 == -1) break;
            int v;
            cin >> v;
            Edge init;
            init.e =enter2;
            init.weight = v;
            ArrayList[enter].push_back(init);
        }
        
    }
    
    for(int i=1; i<=v; i++)     //초기화
    {
        visited[i] = false;
        dist[i] = 0;
    }
    
    BFS(2);
    
    int maxIndex = 1;
    for(int i=2; i<=v; i++) if(dist[maxIndex] < dist[i]) maxIndex = i;
    
    for(int i=1; i<=v; i++)     //초기화
    {
        visited[i] = false;
        dist[i] = 0;
    }
    BFS(maxIndex);
    
    maxIndex = 1;
    for(int i=2; i<=v; i++) if(dist[maxIndex] < dist[i]) maxIndex = i;
    cout << dist[maxIndex];
    
    delete[] dist;
    delete[] visited;
    
}

