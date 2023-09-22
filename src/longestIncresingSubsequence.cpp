#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int INF = 1 << 21;

int main()
{
    int n;
    cin >> n;
    vector<int> text;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        text.push_back(v);
    }

    vector<int> lengthData;
    lengthData.resize(n);
    lengthData.resize(n);
    lengthData[0] = text[0];
    int length = 1;

    for (int i = 1; i < n; i++)
    {
        if (lengthData[length - 1] < text[i])
        {
            lengthData[length++] = text[i];
        }
        else
        {
            *lower_bound(lengthData.begin(), lengthData.begin() + length, text[i]) = text[i];
        }
    }

    cout << length << endl;

    return 0;
}
