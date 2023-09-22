#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int n, e;

vector<vector<long long> > distances; // 始点0からの最短距離
long long  INF = 1LL << 32;

void wFloyd()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (distances[i][k] == INF)
            {
                // エッジがない場合
                continue;
            }
            for (int j = 0; j < n; j++)
            {
                if (distances[k][j] == INF)
                {
                    // エッジがない場合
                    continue;
                }
                // kを経由した方が近い場合は更新する
                distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    distances.resize(n);
    for (int i = 0; i < n; i++)
    {
        distances[i].resize(n, INF);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                distances[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < e; i++)
    {
        long long u, v, c;
        cin >> u >> v >> c;
        distances[u][v] = c;
    }

    wFloyd();

    bool isNegative = false;
    for (int i = 0; i < n; i++)
    {
        if (distances[i][i] < 0)
        {
            isNegative = true;
        }
    }

    if (isNegative)
    {
        cout << "NEGATIVE CYCLE" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
            {
                if (j)
                {
                    cout << " ";
                }
                if (distances[i][j] == INF)
                {
                    cout << "INF";
                }
                else
                {
                    cout << distances[i][j];
                }
            }
            cout << endl;
        }
    }
}
