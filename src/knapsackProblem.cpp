#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int INF = 1 << 21;

struct Info
{
    int value, weight;
};
int main()
{
    int N, W;
    cin >> N >> W;
    vector<Info> goods;
    goods.resize(1);
    for (int i = 0; i < N; i++)
    {
        int v, w;
        cin >> v >> w;
        Info info;
        info.value = v;
        info.weight = w;
        goods.push_back(info);
    }

    vector<vector<int> > totalValue;
    vector<vector<bool> > choose;
    totalValue.resize(N + 1);
    choose.resize(N + 1);
    for (int i = 0; i < N + 1; i++)
    {
        totalValue[i].resize(W + 1);
        totalValue[i][0] = 0;
        choose[i].resize(W + 1, false);
    }
    for (int w = 0; w < W + 1; w++)
    {
        totalValue[0][w] = 0;
    }


    for (int i = 1; i < N + 1; i++)
    {
        for (int w = 1; w < W + 1; w++)
        {
            totalValue[i][w] = totalValue[i - 1][w];
            if (goods[i].weight <= w)
            {
                if (totalValue[i][w] < totalValue[i - 1][w - goods[i].weight] + goods[i].value)
                {
                    totalValue[i][w] = totalValue[i - 1][w - goods[i].weight] + goods[i].value;
                    choose[i][w] = true;
                }
            }
        }
    }

    int maxValue = totalValue[N][W];
    cout << maxValue << endl;

    return 0;
}
