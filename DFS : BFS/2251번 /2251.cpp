#include <iostream>
#include <queue>

using namespace std;

int sender[6] = { 0,0,1,1,2,2 };
int receiver[6] = { 1,2,0,2,0,1 };
bool visited[201][201]; //a,b물통
bool answer[201];
int init[3];

class ab
{
public:
    int a;
    int b;
};

void bfs()
{
    queue<ab> q;
    ab tmp;
    tmp.a = 0;
    tmp.b = 0;

    q.push(tmp);
    visited[0][0] = true;
    answer[init[2]] = true;

    while (!q.empty())
    {
        ab p = q.front();
        q.pop();
        int a = p.a;
        int b = p.b;
        int c = init[2] - a - b;
        for (int x = 0; x < 6; x++)
        {
            int next[3] = { a,b,c };
            next[receiver[x]] += next[sender[x]];
            next[sender[x]] = 0;

            if (next[receiver[x]] > init[receiver[x]])
            {
                next[sender[x]] = (next[receiver[x]] - init[receiver[x]]);
                next[receiver[x]] = init[receiver[x]];
            }

            if (!visited[next[0]][next[1]])
            {
                visited[next[0]][next[1]] = true;
                tmp.a = next[0];
                tmp.b = next[1];
                q.push(tmp);
                if(next[0] == 0)answer[next[2]] = true;

            }
        }
    }

}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> init[0] >> init[1] >> init[2];
    /*for (int i = 0; i < 201; i++)
    {
        answer[i] = false;
        for (int j = 0; j < 201; j++) visited[i][j] = false;
    }*/

    bfs();

    for (int i = 0; i < 201; i++) if (answer[i]) cout << i << " ";
   
}

