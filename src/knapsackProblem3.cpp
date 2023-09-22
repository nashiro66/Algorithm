#include <iostream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;

struct Info
{
    int value, weight;
};
vector<Info> knapsack;
vector<vector<long long> > dp; // 価値を入れる

int main()
{
    int N, W;
    cin >> N >> W;
    dp.resize(N + 1);
    for (int i = 0; i < N + 1; i++)
    {
        dp[i].resize(10005, 1 << 30);
    }


    knapsack.resize(N);
    for (int i = 0; i < N; i++)
    {
        int v, w;
        cin >> v >> w;
        knapsack[i].value = v;
        knapsack[i].weight = w;
    }

    dp[0][0] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int v = 0; v < 10005; v++)
        {
            if (knapsack[i].value <= v)
            {
                dp[i + 1][v] = min(dp[i][v - knapsack[i].value] + knapsack[i].weight, dp[i][v]);
            }
            else
            {
                dp[i + 1][v] = dp[i][v];
            }
        }
    }

    for (int i = 10004; 0 <= i; i--)
    {
        if (dp[N][i] <= W)
        {
            cout << i << endl;
            return 0;
        }
    }
}
