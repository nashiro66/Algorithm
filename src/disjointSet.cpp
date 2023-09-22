#include <vector>
#include <iostream>
#include <queue>
using namespace std;
int n, q;

class DisjointSet
{
public:

    DisjointSet(int size)
    {
        ranks.resize(n, 0);
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

int main()
{
    cin >> n >> q;
    DisjointSet ds = DisjointSet(n);

    for (int i = 0; i < q; i++)
    {
        int order;
        cin >> order;
        int x, y;
        cin >> x >> y;
        if (order == 0)
        {
            ds.UniteSet(x, y);
        }
        else if (order == 1)
        {
            bool ans = ds.Same(x, y);
            if (ans == true)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
}
