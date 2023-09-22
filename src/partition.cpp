#include <vector>
#include <iostream>
using namespace std;

int Partition(vector<int>& A, int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap(A[i], A[j]);

        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int>nums;
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans = Partition(nums, 0, nums.size() - 1);
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == ans)
        {
            cout << "[";
        }
        cout << nums[i];
        if (i == ans)
        {
            cout << "]";
        }
        if (i != nums.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}
