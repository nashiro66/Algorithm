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
    for (int i = 0; i < n; i++)
    {
        int min = nums[i];
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < min)
            {
                min = nums[j];
                minIndex = j;
            }
        }
        if (i != minIndex)
        {
            swap(nums[i], nums[minIndex]);
            count++;
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
