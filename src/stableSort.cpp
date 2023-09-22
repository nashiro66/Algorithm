#include <vector>
#include <iostream>
using namespace std;

bool CheckIsStable(vector<string> sortedNums, vector<string> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = 0; k < nums.size(); k++)
            {
                for (int l = k + 1; l < nums.size(); l++)
                {
                    if (nums[i][1] == nums[j][1] && nums[i] == sortedNums[l] && nums[j] == sortedNums[k])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

vector<string> BubbleSort(vector<string>nums, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - 1; i <= j; j--)
        {
            if (nums[j][1] - '0' < nums[j - 1][1] - '0')
            {
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
    return nums;
}

vector<string> SelectionSort(vector<string>nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = nums[i][1] - '0';
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j][1] - '0' < min)
            {
                min = nums[j][1] - '0';
                minIndex = j;
            }
        }
        if (i != minIndex)
        {
            swap(nums[i], nums[minIndex]);
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
    return nums;
}

int main()
{
    int n;
    cin >> n;
    vector<string>nums;
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<string> sortedNums = BubbleSort(nums, n);
    cout << endl;
    bool isStable = CheckIsStable(sortedNums, nums);
    if (isStable)
    {
        cout << "Stable" << endl;
    }
    else
    {
        cout << "Not stable" << endl;
    }
    sortedNums = SelectionSort(nums, n);
    cout << endl;
    isStable = CheckIsStable(sortedNums, nums);
    if (isStable)
    {
        cout << "Stable" << endl;
    }
    else
    {
        cout << "Not stable" << endl;
    }
}
