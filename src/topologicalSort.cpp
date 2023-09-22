#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int v, e;

vector<vector<int> > graph;
vector<bool> visited;
vector<int> inDegree;
long long  INF = 1LL << 32;
vector<int> out;

void Bfs(int startNode)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        out.push_back(currentNode);
        for (int nextNodeIdx = 0; nextNodeIdx < graph[currentNode].size(); nextNodeIdx++) {
            int nextNode = graph[currentNode][nextNodeIdx];
            inDegree[nextNode]--;
            if (inDegree[nextNode] == 0 && !visited[nextNode])
            {
                visited[nextNode] = true;
                q.push(nextNode);
            }
        }
    }
}


void tSort()
{
    inDegree.resize(v);
    for (int currentNode = 0; currentNode < v; currentNode++)
    {
        for (int nextNodeIdx = 0; nextNodeIdx < graph[currentNode].size(); nextNodeIdx++)
        {
            int nextNode = graph[currentNode][nextNodeIdx];
            inDegree[nextNode]++;
        }
    }

    for (int currentNode = 0; currentNode < v; currentNode++)
    {
        if (inDegree[currentNode] == 0 && !visited[currentNode])
        {
            Bfs(currentNode);
        }
    }

    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << endl;
    }
}

int main()
{
    cin >> v >> e;
    visited.resize(v, false);
    graph.resize(v);

    for (int i = 0; i < e; i++)
    {
        long long u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    tSort();

}
