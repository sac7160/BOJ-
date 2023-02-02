#include <iostream>
#include <queue>
#include <string>

class pos
{
public:
    pos(int row, int col, int wall) {
        this->row = row;
        this->col = col;
        this->wall = wall;
    }
    int row;
    int col;
    int wall;
};

int main()
{
    using namespace std;

    int*** visited = new int** [1001];
    short** board = new short* [1001];
    for (int i = 0; i < 1001; i++)
    {
        board[i] = new short[1001];
    }
    for (int i = 0; i < 1001; i++)
    {
        visited[i] = new int*[1001];
        for (int j = 0; j < 1001; j++) visited[i][j] = new int[2];
    }
    
    
    int row, col;
    cin >> row >> col;

    //(1,1)에서 (n,m)으로 이동

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    

    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            board[i][j] = 0;
            visited[i][j][0] = 0;
            visited[i][j][1] = 0;
        }
    }


    for (int i = 1; i <= row; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 1; j <= col; j++)
        {
            board[i][j] = tmp[j-1] - '0';
        }
    }

    queue <pos> q;
    q.push(pos(1, 1,0));
    board[1][1] = 1;
    visited[1][1][0] = 1;

    while (!q.empty())
    {
        pos cur = q.front();
        q.pop();

        if (cur.row == row && cur.col == col) break;

        for (int i = 0; i < 4; i++)
        {
            int cur_row = cur.row + dy[i];
            int cur_col = cur.col + dx[i];

            if (cur_row <1 || cur_row > row || cur_col < 1 || cur_col > col) continue;

            /*if (visited[cur.row][cur.col][0] != 0 && visited[cur.row][cur.col][1] == 0)    //이전까지 벽을 안뚫었다면
            {
                if (board[cur_row][cur_col] == 1)
                {
                    visited[cur_row][cur_col][1] = visited[cur.row][cur.col][0] + 1;
                    q.push(pos(cur_row, cur_col));
                }
                else
                {
                    visited[cur_row][cur_col][0] = visited[cur.row][cur.col][0] + 1;
                    q.push(pos(cur_row, cur_col));
                }
            }
            else    //이전까지 벽을 뚫었다면
            {
                if (board[cur_row][cur_col] == 1)
                {
                    continue;
                }
                else
                {
                    visited[cur_row][cur_col][1] = visited[cur.row][cur.col][1] + 1;
                    q.push(pos(cur_row, cur_col));
                }
            }*/
            if (visited[cur_row][cur_col][cur.wall] == 0)
            {
                if (board[cur_row][cur_col] == 0)
                {
                    visited[cur_row][cur_col][cur.wall] = visited[cur.row][cur.col][cur.wall] + 1;
                    q.push(pos(cur_row, cur_col, cur.wall));
                }
                if (cur.wall == 0 && board[cur_row][cur_col] == 1)
                {
                    visited[cur_row][cur_col][1] = visited[cur.row][cur.col][0] + 1;
                    q.push(pos(cur_row, cur_col, 1));
                }
            }
        }
    }
    
    if (visited[row][col][0] == 0 && visited[row][col][1] == 0) cout << -1;
    else if (visited[row][col][0] != 0)cout << visited[row][col][0];
    else cout << visited[row][col][1];

    delete[] visited;
    delete[] board;
}
