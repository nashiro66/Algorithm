#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    vector<int> S;
    int q;
    vector<int> T;
    cin >> n;
    S.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    cin >> q;
    T.resize(q);
    for (int i = 0; i < q; i++)
    {
        cin >> T[i];
    }

    int count = 0;
    for (int i = 0; i < q; i++)
    {
        bool found = false;
        int left = 0;
        int right = n - 1;
        int middle = (left + right) / 2;

        //while (!found && 0 <= middle && middle < n)
        //{
        //    if (S[middle] == T[i])
        //    {
        //        found = true;
        //        count++;
        //    }
        //    else if (S[middle] < T[i])
        //    {
        //        left = middle + 1;
        //    }
        //    else if (T[i] < S[middle])
        //    {
        //        right = middle - 1;
        //    }
        //    if (right < left)
        //    {
        //        break;
        //    }
        //    middle = (left + right) / 2;
        //}

        // STLを用いる場合
        if (*lower_bound(S.begin(), S.end(), T[i]) == T[i])
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
