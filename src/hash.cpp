#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int M = 1046527;

int GetChar(char c)
{
    if (c == 'A')
    {
        return 1;
    }
    if (c == 'C')
    {
        return 2;
    }
    if (c == 'G')
    {
        return 3;
    }if (c == 'T')
    {
        return 4;
    }
    return 0;
}

int GetKey(string str)
{
    long long sum = 0, p = 1;
    for (int i = 0; i < str.size(); i++)
    {
        sum += p * GetChar(str[i]);
        p *= 5;
    }
    return sum;
}

int H1(int key)
{
    return key % M;
}

int H2(int key)
{
    return 1 + (key % (M - 1));
}

int main()
{
    int n;
    cin >> n;
    unordered_map<int, string> H;
    for (int i = 0; i < n; i++)
    {
        string order;
        cin >> order;
        string data;
        cin >> data;
        if (order[0] == 'i')
        {
            int key = GetKey(data);
            int loopNum = 0;
            while (true)
            {
                int h = H1(key) + loopNum * (H2(key)) % M;
                if (H[h] == data)
                {
                    break;
                }
                if (H[h].empty())
                {
                    H[h] = data;
                    break;
                }
                loopNum++;
            }
        }
        if (order[0] == 'f')
        {
            int key = GetKey(data);
            int loopNum = 0;
            while (true)
            {
                int h = H1(key) + loopNum * (H2(key)) % M;
                if (H[h] == data)
                {
                    cout << "yes" << endl;
                    break;
                }
                else if (H[h].empty())
                {
                    cout << "no" << endl;
                    break;
                }
                loopNum++;
            }
        }
    }
    return 0;
}
