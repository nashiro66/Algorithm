#include <vector>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
int v, e;

vector<vector<int> > graph;
vector<bool> visited;
vector<int> parents;
vector<int> lowest; // 繋がっているか確認するための順番
vector<int> visitedOrder; // 訪問の順番
int timer = 1;
long long  INF = 1LL << 32;

// lowestの計算を行う
void Dfs(int currentNode, int prevNode)
{
    visitedOrder[currentNode] = lowest[currentNode] = timer;
    timer++;

    visited[currentNode] = true;

    for (int nextNodeIdx = 0; nextNodeIdx < graph[currentNode].size(); nextNodeIdx++)
    {
        int nextNode = graph[currentNode][nextNodeIdx];
        if (!visited[nextNode])
        {
            parents[nextNode] = currentNode;
            Dfs(nextNode, currentNode);
            // ノード探索終了後
            lowest[currentNode] = min(lowest[currentNode], lowest[nextNode]);
        }
        else if (nextNode != prevNode)
        {
            // 訪問済みだった場合の訪問時間が現在のノードより先だったら更新
            lowest[currentNode] = min(lowest[currentNode], visitedOrder[nextNode]);
        }
    }
}

void artPoints()
{
    Dfs(0, -1);

    set<int> ap;
    int np = 0;
    for (int i = 1; i < v; i++)
    {
        int parent = parents[i];
        if (parent == 0)
        {
            np++;
        }
        else if (visitedOrder[parent] <= lowest[i])
        {
            ap.insert(parent);
        }
    }

    if (np > 1)
    {
        ap.insert(0);
    }
    for (auto it = ap.begin(); it != ap.end(); it++)
    {
        cout << *it << endl;
    }
}

int main()
{
    cin >> v >> e;
    visited.resize(v, false);
    parents.resize(v);
    visitedOrder.resize(v);
    lowest.resize(v);
    graph.resize(v);

    for (int i = 0; i < e; i++)
    {
        long long u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    artPoints();
}
