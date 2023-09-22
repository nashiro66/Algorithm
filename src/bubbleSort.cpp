#include <vector>
#include <iostream>
using namespace std;

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

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - 1; i <= j; j--)
        {
            if (nums[j] < nums[j - 1])
            {
                count++;
                swap(nums[j - 1], nums[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i];
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    cout << count << endl;
}
