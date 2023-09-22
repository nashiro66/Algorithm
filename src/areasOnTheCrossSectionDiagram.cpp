#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

struct info
{
    int index = 0;
    int area = 0;
};
int main()
{
    string input;
    cin >> input;
    stack<int> s;
    stack<info> puddles;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '\\')
        {
            s.push(i);
        }
        else if (input[i] == '/' && s.size() != 0)
        {
            int end = i;
            int start = s.top();
            s.pop();
            int area = end - start;
            while (0 < puddles.size() && start < puddles.top().index)
            {
                area += puddles.top().area;
                puddles.pop();
            }
            info p;
            p.index = start;
            p.area = area;
            puddles.push(p);
        }
    }

    int sum = 0;
    vector<int> areas;
    for (int i = 0; puddles.size() != 0; i++)
    {
        areas.push_back(puddles.top().area);
        sum += puddles.top().area;
        puddles.pop();
    }
    cout << sum << endl;
    cout << areas.size();
    for (int i = areas.size() - 1; 0 <= i; i--)
    {
        cout << " ";
        cout << areas[i];
    }
    cout << endl;

    return 0;
}
