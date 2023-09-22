#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int INF = 1 << 21;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dp(500001, INF);
    vector<int> coins;
    for (int i = 0; i < m; i++)
    {
        int c;
        cin >> c;
        coins.push_back(c);
    }

    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto coin : coins)
        {
            dp[i + coin] = min(dp[i + coin], dp[i] + 1);
        }
    }

    cout << dp[n] << endl;

    return 0;
}
