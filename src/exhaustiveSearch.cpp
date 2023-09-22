#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int n;
vector<int> A;
bool Solve(int i, int m)
{
    if (m == 0)
    {
        return true;
    }
    if (i >= n)
    {
        return false;
    }
    int res = Solve(i + 1, m) || Solve(i + 1, m - A[i]);
    return res;
}

int main()
{
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int q;
    cin >> q;
    vector<int> M;
    M.resize(q);
    for (int i = 0; i < q; i++)
    {
        cin >> M[i];
    }

    for (int i = 0; i < q; i++)
    {
        if (Solve(0, M[i]))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
