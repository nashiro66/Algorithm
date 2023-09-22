#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int n;
vector<long long> T;
int truckNum = 0;

int Check(long long maxWeight)
{
    int loadIndex = 0;
    for (int j = 0; j < truckNum; j++)
    {
        long long s = 0;
        while (s + T[loadIndex] <= maxWeight)
        {
            s += T[loadIndex];
            loadIndex++;
            if (loadIndex == n)
            {
                // 全て積み終わったら
                return n;
            }
        }
    }
    // 全ては積み終わらなかったら
    return loadIndex;
}

int Solve()
{
    long long left = 0;
    long long right = 100000 * 10000;
    long long mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        int v = Check(mid); // maxWeight=midでいくつ積めるか確認
        if (v >= n)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right;
}

int main()
{
    cin >> n;
    cin >> truckNum;
    T.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> T[i];
    }

    long long ans = Solve();
    cout << ans << endl;
    return 0;
}
