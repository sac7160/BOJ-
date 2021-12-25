//1260번

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
void DFS(int);
void BFS(int);
bool visited[1001];
vector<int> graph[1001];
queue<int>tmp;

int main()
{
	int n, m, v;
	cin >> n >> m >> v; 
	fill(visited, visited + 1001, false);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i= 0; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	DFS(v);
	cout << '\n';
	fill(visited, visited + 1001, false);
	BFS(v);
	
	return 0;
}

void DFS(int v)
{
	visited[v] = true;
	cout << v << " ";

	for (int i = 0; i < graph[v].size(); i++)
	{
		int x = graph[v][i];
		if (!visited[x]) DFS(x);
	}
}

void BFS(int v)
{
	tmp.push(v);
	visited[v] = true;

	while (!tmp.empty())
	{
		int x = tmp.front();
		tmp.pop();

		cout << x << " ";
		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (!visited[y])
			{
				tmp.push(y);
				visited[y] = true;
			}
		}
	}
	

}