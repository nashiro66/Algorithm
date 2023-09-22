#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int n;

enum Color
{
    black, gray, white
};

vector<vector<int> > adjs;
vector<Color> colors;
vector<int> distances;
int INF = 1 << 21;

void Bfs()
{
    colors.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        colors[i] = white;
    }
    distances.resize(n + 1, INF);
    queue<int> q;
    q.push(1);
    distances[1] = 0;
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();
        for (int nextNode = 1; nextNode <= n; nextNode++)
        {
            if (adjs[currentNode][nextNode] == 0)
            {
                // エッジがない場合
                continue;
            }
            if (distances[nextNode] != INF)
            {
                // 既に最短距離が格納されている場合
                continue;
            }
            distances[nextNode] = distances[currentNode] + 1;
            q.push(nextNode);
        }

    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
        if (distances[i] == INF)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << distances[i] << endl;
        }
    }
}

int main()
{
    cin >> n;
    adjs.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        adjs[i].resize(n + 1, 0);
    }

    for (int i = 0; i < n; i++)
    {
        int currentNode;
        cin >> currentNode;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int nextNode;
            cin >> nextNode;
            adjs[currentNode][nextNode] = 1;
        }
    }

    Bfs();
}
