#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int v, e;
int INF = 1 << 21;
static const int MAX = 10000;

class DisjointSet
{
public:

    DisjointSet(int size)
    {
        ranks.resize(size, 0);
        parents.resize(size, 0);
        for (int i = 0; i < size; i++)
        {
            MakeSet(i);
        }
    }


    void MakeSet(int x)
    {
        parents[x] = x;
        ranks[x] = 0;
    }

    int FindSet(int x)
    {
        int parent = x;
        if (x != parents[x])
        {
            parent = FindSet(parents[x]);
        }
        return parent;
    }

    void Link(int x, int y)
    {
        if (ranks[x] < ranks[y])
        {
            parents[x] = y;
        }
        else
        {
            parents[y] = x;
            if (ranks[x] == ranks[y])
            {
                ranks[x]++;
            }
        }
    }

    void UniteSet(int x, int y)
    {
        Link(FindSet(x), FindSet(y));
    }

    bool Same(int x, int y)
    {
        return FindSet(x) == FindSet(y);
    }

private:
    vector<int> parents;
    vector<int> ranks;
};

class Edge
{
public:
    Edge() {}
    Edge(int u, int v, int w)
    {
        start = u;
        end = v;
        weight = w;
    }
    bool operator < (const Edge& e)
    {
        return weight < e.weight;
    }

    int start, end, weight;
};

enum Color
{
    black, gray, white
};

vector<Edge> edges;
vector<Color> colors;
vector<int> distances; // 始点0からの最短距離


void kruskal()
{
    // 重みの小さい順にソート
    sort(edges.begin(), edges.end());
    DisjointSet dset = DisjointSet(v + 1);
    for (int i = 0; i < v; i++)
    {
        dset.MakeSet(i);
    }

    int totalCost = 0;
    // 重みの小さい順から木を連結していく
    for (int i = 0; i < edges.size(); i++)
    {
        Edge e = edges[i];
        if (!dset.Same(e.start, e.end))
        {
            totalCost += e.weight;
            dset.UniteSet(e.start, e.end);
        }
    }
    cout << totalCost << endl;
}

int main()
{
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    kruskal();
}
