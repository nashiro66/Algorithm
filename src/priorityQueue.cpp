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

void Insert(vector<int>& heapTree, int insertNum)
{
    n++;
    heapTree.push_back(insertNum);
    int i = n;
    while (i > 1 && heapTree[i / 2] < heapTree[i])
    {
        swap(heapTree[i / 2], heapTree[i]);
        i = i / 2;
    }
}

int Extract(vector<int>& heapTree)
{
    int max = heapTree[1];
    heapTree[1] = heapTree[n];
    heapTree.pop_back();
    n--;
    MaxHeapify(heapTree, 1);
    return max;
}

int main()
{
    vector<int> heapTree(1);
    while (true)
    {
        string s;
        cin >> s;
        if (s == "insert")
        {
            int a;
            cin >> a;
            Insert(heapTree, a);
        }
        else if (s == "extract")
        {
            int ans = Extract(heapTree);
            cout << ans << endl;
        }
        else
        {
            return 0;
        }
    }
}
