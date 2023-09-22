#include <vector>
#include <iostream>
using namespace std;

void CountingSort(vector<int> A, vector<int>& B, int k)
{
    vector<int> C(k, 0);

    for (int i = 0; i < A.size(); i++)
    {
        // C[i] contains the number of i.
        C[A[i]]++;
    }
    for (int i = 1; i < k; i++)
    {
        // C[i] contains the number of elements below i.
        C[i] = C[i] + C[i - 1];
    }
    for (int i = A.size() - 1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int>inputs;
    inputs.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inputs[i];
    }
    vector<int> outputs(n, 0);
    CountingSort(inputs, outputs, 2000001);

    for (int i = 0; i < inputs.size(); i++)
    {
        cout << outputs[i];
        if (i != outputs.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}
