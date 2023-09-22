#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>prices;
    prices.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    int maxv = -2000000000;
    int minv = prices[0];
    for (int i = 1; i < n; i++)
    {
        maxv = max(maxv, prices[i] - minv);
        minv = min(minv, prices[i]);
    }

    cout << maxv << endl;
}
