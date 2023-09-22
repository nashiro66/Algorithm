#include <vector>
#include <iostream>
using namespace std;

void InsertionSort(vector<int>& nums, int n, int g, int& count)
{
    for (int i = g; i < n; i++)
    {
        int insertNum = nums[i];
        int j = i - g;
        while (0 <= j && insertNum < nums[j]) {
            nums[j + g] = nums[j];
            j -= g;
            count++;
        }
        nums[j + g] = insertNum;
    }
}

void ShellSort(vector<int> nums, int n)
{
    int count = 0;
    vector<int> G;
    for (int i = 1; i <= n; i = i * 3 + 1)
    {
        G.push_back(i);
    }

    for (int i = 0; i < G.size(); i++)
    {
        InsertionSort(nums, n, G[G.size() - 1 - i], count);
    }
    cout << G.size() << endl;
    for (int i = 0; i < G.size(); i++)
    {
        cout << G[G.size() - 1 - i];
        if (i != G.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    cout << count << endl;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
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
    ShellSort(nums, nums.size());
}
