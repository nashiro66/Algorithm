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
vector<int> distances; // 親ノードとの最短距離
int INF = 1 << 21;

void Bfs()
{
    colors.resize(n, white);
    for (int i = 1; i < n; i++)
    {
        colors[i] = white;
    }
    distances.resize(n, INF);

    vector<int> parents(n, -1);
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
                // 次のノードへの最短距離を格納
                if (distances[nextNodeIdx] > adjs[currentNodeIdx][nextNodeIdx])
                {
                    distances[nextNodeIdx] = adjs[currentNodeIdx][nextNodeIdx];
                    parents[nextNodeIdx] = currentNodeIdx;
                    colors[nextNodeIdx] = gray;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (parents[i] != -1)
        {
            sum += adjs[i][parents[i]];
        }
    }
    cout << sum << endl;
}

int main()
{
    cin >> n;
    adjs.resize(n);
    for (int i = 0; i < n; i++)
    {
        adjs[i].resize(n, 0);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int nextNode;
            cin >> nextNode;
            if (nextNode == -1)
            {
                adjs[i][j] = INF;
            }
            else
            {
                adjs[i][j] = nextNode;
            }
        }
    }

    Bfs();
}

