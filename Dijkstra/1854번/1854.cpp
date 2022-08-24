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
    bool operator()(node a, node b) {
        return a.value > b.value;

    }
};


int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;

    cin >> n >> m >> k;

    int** route = new int* [n + 1];
    for (int i = 0; i < n + 1; i++) route[i] = new int[n + 1];

    priority_queue<int, vector<int>, less<>> k_queue[1001];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) route[i][j] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        route[a][b] = c;
    }

    priority_queue<node, vector<node>, compare> q;

    q.push(node(1, 0));
    k_queue[1].push(0);

    while (!q.empty())
    {
        node u = q.top();
        q.pop();

        for (int adjNode = 1; adjNode <= n; adjNode++)
        {
            if (route[u.target][adjNode] != 0)
            {
                if (k_queue[adjNode].size() < k)
                {
                    k_queue[adjNode].push(u.value + route[u.target][adjNode]);
                    q.push(node(adjNode, u.value+route[u.target][adjNode]));
                }
                else if (k_queue[adjNode].top() > u.value + route[u.target][adjNode])
                {
                    k_queue[adjNode].pop();
                    k_queue[adjNode].push(u.value + route[u.target][adjNode]);
                    q.push(node(adjNode, u.value + route[u.target][adjNode]));
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (k_queue[i].size() == k) cout << k_queue[i].top() << '\n';
        else cout << -1 << '\n';
    }

}
