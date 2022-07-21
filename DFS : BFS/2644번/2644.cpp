#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool visited[101];
vector<vector<int>> rel;
vector<int>tmp;
int person1,person2;
bool found= false;

void DFS(int person,int depth)
{
    visited[person] = true;
    if(person == person2) {
        cout<< depth;
        found = true;
        return;
    }
    for(int i=0; i<rel[person].size(); i++)
    {
        if(!visited[rel[person][i]]) DFS(rel[person][i], depth+1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin >> n;
    
    cin >> person1 >> person2;
    
    cin >> m;
    
    for(int i=0; i<=n; i++) {
        rel.push_back(tmp);
        visited[i] = false;
    }
    
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin >> x >> y;
        rel[x].push_back(y);
        rel[y].push_back(x);
    }
    
    DFS(person1,0);
    if(!found) cout << -1;
    
}

