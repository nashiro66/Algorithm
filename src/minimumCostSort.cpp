#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int Solve(vector<int> A)
{
    int ans = 0;
    int minOfAll = 10000;
    for (int i = 0; i < n; i++)
    {
        if (A[i] < minOfAll)
        {
            minOfAll = A[i];
        }
    };

    vector<bool> visited(n, false);
    vector<int> B;
    B.resize(n);
    for (int i = 0; i < n; i++)
    {
        B[i] = A[i];
    }
    sort(B.begin(), B.end());
    vector<int> T(10000);
    for (int i = 0; i < n; i++)
    {
        T[B[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            continue;
        }
        int currentIdx = i;
        int sum = 0;
        int minOfLoop = 10000;
        int swapNum = 0;
        while (true)
        {
            swapNum++;
            visited[currentIdx] = true;
            int v = A[currentIdx];
            sum += v;
            minOfLoop = min(minOfLoop, v);
            currentIdx = T[v];
            if (visited[currentIdx])
            {
                break;
            }
        }
        ans += min(sum + (swapNum - 2) * minOfLoop, sum + minOfLoop + (swapNum + 1) * minOfAll);
    }
    return ans;
}


int main()
{
    cin >> n;
    vector<int>nums;
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans = Solve(nums);
    cout << ans << endl;
}
