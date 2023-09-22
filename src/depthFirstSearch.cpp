#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;

enum Color
{
    black, gray, white
};

vector<vector<int> > adjs;
vector<Color> colors;
vector<int> startTime;
vector<int> endTime;
int t;

void DfsVisit(int node)
{
    colors[node] = gray;
    startTime[node] = ++t;
    for (int nextNode = 1; nextNode <= n; nextNode++)
    {
        if (adjs[node][nextNode] == 0)
        {
            // 探索すべきエッジがない場合
            continue;
        }
        if (colors[nextNode] == white)
        {
            DfsVisit(nextNode);
        }
    }
    colors[node] = black;
    endTime[node] = ++t;
}

void Dfs()
{
    colors.resize(n + 1);
    startTime.resize(n + 1);
    endTime.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        colors[i] = white;
    }

    for (int i = 1; i <= n; i++)
    {
        if (colors[i] == white)
        {
            DfsVisit(i);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << startTime[i] << " " << endTime[i] << endl;
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
        int node;
        cin >> node;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int v;
            cin >> v;
            adjs[node][v] = 1;
        }
    }

    Dfs();
}
