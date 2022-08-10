#include <iostream>
#include <vector>

using namespace std;


int * parent;

int find(int a)
{
    if(a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a!=b) parent[b] = a;
}


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    
    int city[201][201];
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) cin >> city[i][j] ;
    }
    
    vector<int> route;
    int tmp;
    for(int i=0; i<m; i++)
    {
        cin >> tmp;
        route.push_back(tmp);
    }
    
    parent = new int[n+1];
    
    for(int i=1; i<=n; i++) parent[i] = i;
    
    //초기화
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(city[i][j])
            {
                Union(i,j);
            }
        }
    }
    
    int index = parent[route[0]];
    
    for(int i=1; i<route.size(); i++)
    {
        if(index != find(route[i]))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    
    delete[] parent;
   
}

