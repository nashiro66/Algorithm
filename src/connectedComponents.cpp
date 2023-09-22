#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int n, m;

vector<vector<int> > adjs;
vector<int> colors;
vector<int> distances;
int id = 1;
int INF = 1 << 21;

void Bfs(int startNode)
{
    queue<int> q;
    q.push(startNode);
    distances[startNode] = 0;
    colors[startNode] = id;
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        for (int nextNodeIdx = 0; nextNodeIdx < adjs[currentNode].size(); nextNodeIdx++)
        {
            int nextNode = adjs[currentNode][nextNodeIdx];
            if (colors[nextNode] == id)
            {
                // 訪問済みの場合
                continue;
            }
            if (distances[nextNode] != INF)
            {
                // 既に最短距離が格納されている場合
                continue;
            }
            distances[nextNode] = distances[currentNode] + 1;
            colors[nextNode] = id;
            q.push(nextNode);
        }

    }
}

int main()
{
    cin >> n >> m;
    adjs.resize(n);

    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        adjs[start].push_back(end);
        adjs[end].push_back(start);
    }

    colors.resize(n);
    for (int i = 1; i < n; i++)
    {
        colors[i] = 0;
    }
    // 色の割り当て
    for (int node = 0; node < n; node++)
    {
        distances.resize(n, INF);
        if (colors[node] == 0)
        {
            Bfs(node);
        }
        id++;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (colors[a] == colors[b])
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
}
