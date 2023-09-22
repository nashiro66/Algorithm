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
vector<int> distances; // 始点0からの最短距離
int INF = 1 << 21;

void dijkstra()
{
    colors.resize(n, white);
    for (int i = 1; i < n; i++)
    {
        colors[i] = white;
    }
    distances.resize(n, INF);
    distances[0] = 0;

    while (1)
    {
        int minDistance = INF;
        int currentNodeIdx = -1;
        for (int i = 0; i < n; i++)
        {
            if (minDistance > distances[i] && colors[i] != black)
            {
                currentNodeIdx = i;
                minDistance = distances[i];
            }
        }

        if (currentNodeIdx == -1)
        {
            // 全て訪問済みblackになった場合
            break;
        }

        colors[currentNodeIdx] = black;
        for (int nextNodeIdx = 0; nextNodeIdx < n; nextNodeIdx++)
        {
            // 未訪問で辺がある場合
            if (colors[nextNodeIdx] != black && adjs[currentNodeIdx][nextNodeIdx] != INF)
            {
                // 始点からの最短距離を格納
                if (distances[nextNodeIdx] > distances[currentNodeIdx] + adjs[currentNodeIdx][nextNodeIdx])
                {
                    distances[nextNodeIdx] = distances[currentNodeIdx] + adjs[currentNodeIdx][nextNodeIdx];
                    colors[nextNodeIdx] = gray;
                }
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
        if (distances[i] == INF)
        {
            cout << -1 << endl;
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
    adjs.resize(n);
    for (int i = 0; i < n; i++)
    {
        adjs[i].resize(n, INF);
    }

    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int v, c;
            cin >> v >> c;
            adjs[u][v] = c;
        }
    }
    dijkstra();
}
