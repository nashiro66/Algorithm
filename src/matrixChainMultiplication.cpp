#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Matrix
{
    int row;
    int col;
};

int main()
{
    int n;
    cin >> n;
    vector<Matrix> matrix(n);
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> matrix[i].row >> matrix[i].col;
    }

    for (int columnCount = 2; columnCount <= n; columnCount++)
    {
        for (int startIdx = 0; startIdx < n - columnCount + 1; startIdx++)
        {
            int endIdx = startIdx + columnCount - 1;
            dp[startIdx][endIdx] = 1 << 21;
            for (int k = startIdx; k < endIdx; k++)
            {
                dp[startIdx][endIdx] = min(dp[startIdx][endIdx], dp[startIdx][k] + dp[k + 1][endIdx] + matrix[startIdx].row * matrix[k].col * matrix[endIdx].col);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    return 0;
}
