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

    for (int i = 0; i < n; i++)
    {
        cout << nums[i];
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        int insertNum = nums[i + 1];
        for (int j = i; 0 <= j; j--)
        {
            nums[j + 1] = nums[j];
            if (nums[j] < insertNum)
            {
                nums[j + 1] = insertNum;
                break;
            }
            if (j == 0)
            {
                nums[j] = insertNum;
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
    }
}
