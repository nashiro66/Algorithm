#include <vector>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
int n;

class Edge
{
public:
    Edge(int v, int w)
    {
        end = v;
        weight = w;
    }
    int end, weight;
};
vector<vector<Edge> > graph;
vector<int> distances;
int  INF = 1 << 30;

void Bfs(int startNode)
{
    distances.clear();
    distances.resize(n, INF);
    queue<int> q;
    q.push(startNode);
    distances[startNode] = 0;

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        for (int nextNodeIdx = 0; nextNodeIdx < graph[currentNode].size(); nextNodeIdx++)
        {
            int nextNode = graph[currentNode][nextNodeIdx].end;
            if (distances[nextNode] != INF)
            {
                // 既に最短距離が格納されている場合
                continue;
            }
            distances[nextNode] = distances[currentNode] + graph[currentNode][nextNodeIdx].weight;
            q.push(nextNode);
        }
    }
}

void Solve()
{
    // 適当なノード0から最も遠いノードを求める
    Bfs(0);

    int maxValue = 0;
    int tgt = 0;
    for (int i = 0; i < n; i++)
    {
        if (distances[i] == INF)
        {
            continue;
        }
        if (maxValue < distances[i])
        {
            maxValue = distances[i];
            tgt = i;
        }
    }

    // tgtから最も遠いノードを求める
    Bfs(tgt);
    maxValue = 0;
    for (int i = 0; i < n; i++)
    {
        if (distances[i] == INF)
        {
            continue;;
        }
        maxValue = max(maxValue, distances[i]);
    }

    cout << maxValue << endl;
}

int main()
{
    cin >> n;
    graph.resize(n);

    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(Edge(v, w));
        graph[v].push_back(Edge(u, w));
    }
    Solve();
}
