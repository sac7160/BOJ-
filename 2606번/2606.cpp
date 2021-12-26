//
//  main.cpp
//  BOJ
//
//  Created by Changhyeon Park on 2021/10/28.
//
// 2606번

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[101];
bool visited[101];
int ans;
void DFS(int);


int main(void)
{
    ans = 0;
    int computerNum;
    cin >> computerNum;
    int edge;
    cin >> edge;
    fill(visited, visited + 101, false);
    
    for(int i=0; i<edge; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for(int i=0; i<=computerNum; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    
    DFS(1);
    cout << ans;
    
    return 0;
}

void DFS(int init)
{
    visited[init] = true;

    for(int i=0; i<graph[init].size(); i++)
    {
        int x = graph[init][i];
        if(!visited[x])
        {
            ans++;
            DFS(x);
        }
    }
    
}

