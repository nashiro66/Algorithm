#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

void MaxHeapify(vector<int>& heapTree, int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largestIdx = i;
    if (left <= n && heapTree[left] > heapTree[largestIdx])
    {
        largestIdx = left;
    }
    if (right <= n && heapTree[right] > heapTree[largestIdx])
    {
        largestIdx = right;
    }
    if (largestIdx != i)
    {
        swap(heapTree[i], heapTree[largestIdx]);
        MaxHeapify(heapTree, largestIdx);
    }
}

void buildMaxHeap(vector<int>& heapTree)
{
    for (int i = n / 2; i >= 1; i--)
    {
        MaxHeapify(heapTree, i);
    }
}

int main()
{
    cin >> n;
    vector<int> heapTree(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> heapTree[i];
    }

    buildMaxHeap(heapTree);

    for (int i = 1; i <= n; i++)
    {
        cout << " " << heapTree[i];
    }
    cout << endl;
}
