#include <vector>
#include <iostream>
using namespace std;

long long c = 0;
void Merge(vector<int>& A, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L;
    vector<int> R;
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
    L[n1] = 2000000000;
    R[n2] = 2000000000;

    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++)
    {
        if (L[i] < R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            c += n1 - i;
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(vector<int>& A, int left, int right)
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
    vector<int>nums;
    nums.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    MergeSort(nums, 0, nums.size());

    cout << c << endl;
}
