#include <iostream>
#include <queue>



class pos
{
public:
    pos(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
    int x;
    int y;
};

int main()
{
    using namespace std;

    int t;

    int** visited = new int* [300];
    for (int i = 0; i < 300; i++) visited[i] = new int[300];
    int** board = new int* [300];
    for (int i = 0; i < 300; i++) board[i] = new int[300];


    int dx[8] = {1,2,2,1,-1,-2,-2,-1};
    int dy[8] = {2,1,-1,-2,-2,-1,1,2};

    cin >> t;

    for (int test = 0; test < t; test++)
    {
        for (int i = 0; i < 300; i++)
        {
            for (int j = 0; j < 300; j++)
            {
                visited[i][j] = 0;
                board[i][j] = 0;
            }
        }

        int l,x, y, end_x, end_y;

        cin >> l >> y >> x >> end_y >> end_x;

        queue <pos> q;
        q.push(pos(x, y));
        visited[y][x] = 1;


        while (!q.empty())
        {
            pos cur = q.front();
            q.pop();

            //if (cur.x == end_x && cur.y == end_y) break;
            for (int i = 0; i < 8; i++)
            {
                x = cur.x + dx[i];
                y = cur.y + dy[i];
                if (x < 0 || x >= l || y < 0 || y>=l) continue;
                if (visited[y][x] == 0)
                {
                    q.push(pos(x, y));
                    visited[y][x] = 1;
                    board[y][x] = board[cur.y][cur.x] + 1;
                }
            }
            if (board[end_y][end_x] != 0) break;
            
        }

        cout << board[end_y][end_x] << '\n';
    }
    delete[] visited;
    delete[] board;
}
