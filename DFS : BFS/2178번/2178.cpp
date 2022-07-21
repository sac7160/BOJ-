#include <iostream>
#include <queue>
#include <string>

using namespace std;

bool visited[101][101];
int maze[102][102];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

class xy
{
public:
    int x;
    int y;
};

queue<xy> q;

void BFS(int x,int y)
{
    visited[x][y] = true;
    while(!q.empty())
    {
        xy tmp = q.front();
        q.pop();
        visited[tmp.x][tmp.y] = true;
        for(int i=0; i<4; i++)
        {
            int x = tmp.x + dx[i];
            int y = tmp.y + dy[i];
            if (maze[x][y] != 0 && !visited[x][y])
            {
                visited[x][y] = true;
                maze[x][y] = maze[tmp.x][tmp.y] +1;
                xy tmp2;
                tmp2.x = x;
                tmp2.y = y;
                q.push(tmp2);
            }
        }
    }
    
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    
    
    for(int i=0;i<=n+1; i++)
    {
        maze[i][0] = 0;
        maze[i][m+1] = 0;
    }
    for(int i=0;i<=m+1; i++)
    {
        maze[0][i] = 0;
        maze[n+1][i] = 0;
    }
    
    for(int i=1; i<=n; i++)
    {
        string enter;
        cin >> enter;
        
        int tmp;
        
        for(int j=1; j<=m; j++)
        {
            string x(enter.substr(j-1,1));
            tmp = stoi(x);
            maze[i][j] = tmp;
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) visited[i][j] = false;
    }
    
    xy tmp;
    tmp.x = 1;
    tmp.y = 1;
    
    q.push(tmp);
    
    BFS(1,1);
    cout << maze[n][m];
}

