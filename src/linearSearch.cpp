#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int s, t;
    cin >> s;
    vector<int> S;
    vector<int> T;

    S.resize(s);
    for (int i = 0; i < s; i++)
    {
        cin >> S[i];
    }
    cin >> t;
    T.resize(t);
    for (int i = 0; i < t; i++)
    {
        cin >> T[i];
    }

    vector<int> foundList;
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = 0; j < T.size(); j++)
        {
            if (S[i] == T[j])
            {
                if (foundList.size() == 0 || find(foundList.begin(), foundList.end(), S[i]) != foundList.end())
                {
                    foundList.push_back(S[i]);
                }
            }
        }
    }
    cout << foundList.size() << endl;
    return 0;
}
