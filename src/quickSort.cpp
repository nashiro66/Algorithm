#include <vector>
#include <iostream>
using namespace std;

struct Input
{
    int n;
    char c;
};

int Partition(vector<Input>& A, int p, int r)
{
    int x = A[r].n;
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (A[j].n <= x)
        {
            i++;
            swap(A[i], A[j]);

        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

void QuickSort(vector<Input>& A, int p, int r)
{
    if (p < r)
    {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

void Merge(vector<Input>& A, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    vector<Input> L;
    vector<Input> R;
    L.resize(n1 + 1);
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }
    R.resize(n2 + 1);
    for (int i = 0; i < n2; i++)
    {
        R[i] = A[mid + i];
    }
    L[n1].n = 2000000000;
    R[n2].n = 2000000000;

    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++)
    {
        if (L[i].n <= R[j].n)
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(vector<Input>& A, int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid, right);
        Merge(A, left, mid, right);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Input>nums;
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i].c;
        cin >> nums[i].n;
    }

    vector<Input> nums2;
    nums2.resize(n);
    for (int i = 0; i < n; i++)
    {
        nums2[i] = nums[i];
    }

    QuickSort(nums, 0, nums.size() - 1);
    MergeSort(nums2, 0, nums.size());

    bool isStable = true;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i].c != nums2[i].c)
        {
            isStable = false;
            break;
        }
    }

    if (isStable)
    {
        cout << "Stable" << endl;
    }
    else
    {
        cout << "Not stable" << endl;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i].c << " " << nums[i].n;
        cout << endl;
    }
}
