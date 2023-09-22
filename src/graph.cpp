#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
unsigned long long M = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > adjs;
    adjs.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
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

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout << adjs[i][j];
            if (j != n)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
