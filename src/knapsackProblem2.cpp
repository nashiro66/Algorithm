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
vector<int> dp; // 価値を入れる

int main()
{
    int N, W;
    cin >> N >> W;
    dp.resize(W + 1);

    knapsack.resize(N);
    for (int i = 0; i < N; i++)
    {
        int v, w;
        cin >> v >> w;
        knapsack[i].value = v;
        knapsack[i].weight = w;
    }

    for (int w = 0; w <= W; w++)
    {
        for (int i = 0; i < N; i++)
        {
            if (knapsack[i].weight <= w)
            {
                dp[w] = max(dp[w - knapsack[i].weight] + knapsack[i].value, dp[w]);
            }
        }
    }

    cout << dp[W] << endl;
}
