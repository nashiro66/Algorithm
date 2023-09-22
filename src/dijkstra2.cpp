#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int n;
int INF = 1 << 21;
static const int MAX = 10000;

enum Color
{
    black, gray, white
};

vector<pair<int, int> > adjs[MAX];
vector<Color> colors;
vector<int> distances; // 始点0からの最短距離


void dijkstra2()
{
    colors.resize(n, white);
    for (int i = 1; i < n; i++)
    {
        colors[i] = white;
    }
    distances.resize(n, INF);
    distances[0] = 0;

    priority_queue<pair<int, int> > PQ; // 重み, ノード番号の優先度付きキュー
    PQ.push(make_pair(0, 0));

    while (!PQ.empty())
    {
        auto node = PQ.top();
        PQ.pop();
        int currentNodeIdx = node.second;
        colors[currentNodeIdx] = black;


        for (int j = 0; j < adjs[currentNodeIdx].size(); j++)
        {
            // 未訪問で辺がある場合
            if (colors[adjs[currentNodeIdx][j].first] != black)
            {
                // 始点からの最短距離を格納
                if (distances[adjs[currentNodeIdx][j].first] > distances[currentNodeIdx] + adjs[currentNodeIdx][j].second)
                {
                    distances[adjs[currentNodeIdx][j].first] = distances[currentNodeIdx] + adjs[currentNodeIdx][j].second;
                    PQ.push(make_pair(distances[adjs[currentNodeIdx][j].first] * (-1), adjs[currentNodeIdx][j].first));
                    colors[j] = gray;

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
            adjs[u].push_back(make_pair(v, c));
        }
    }

    dijkstra2();
}
