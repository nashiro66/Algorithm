#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct line
{
    int x1, y1;
    int x2, y2;

};

#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

struct EndPoint
{
    int x, y;
    int id;
    int st;
    EndPoint(int x, int y, int id, int st) : x(x), y(y), id(id), st(st) {}
    bool operator<(const EndPoint& other) const
    {
        if (other.y == y)
        {
            return st < other.st;
        }
        else
        {
            return other.y > y;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<line> lines;
    lines.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
    }

    vector<EndPoint> endpoints;
    for (int i = 0; i < n; i++)
    {
        if (lines[i].y1 == lines[i].y2)
        {
            if (lines[i].x1 > lines[i].x2)
            {
                swap(lines[i].x1, lines[i].x2);
            }
        }
        else if (lines[i].y1 > lines[i].y2)
        {
            swap(lines[i].y1, lines[i].y2);
            swap(lines[i].x1, lines[i].x2);
        }

        if (lines[i].y1 == lines[i].y2)
        {
            // 水平線分を端点リストへ追加
            endpoints.push_back(EndPoint(lines[i].x1, lines[i].y1, i, LEFT));
            endpoints.push_back(EndPoint(lines[i].x2, lines[i].y2, i, RIGHT));
        }
        else
        {
            // 垂直線分を端点リストへ追加
            endpoints.push_back(EndPoint(lines[i].x1, lines[i].y1, i, BOTTOM));
            endpoints.push_back(EndPoint(lines[i].x2, lines[i].y2, i, TOP));
        }
    }

    sort(endpoints.begin(), endpoints.end());
    set<int> BinaryTree;
    BinaryTree.insert(100000000001);
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (endpoints[i].st == TOP)
        {
            BinaryTree.erase(endpoints[i].x); // 線分の上端点を削除
        }
        else if (endpoints[i].st == BOTTOM)
        {
            BinaryTree.insert(endpoints[i].x); // 線分の下端点を挿入
        }
        else if (endpoints[i].st == LEFT)
        {
            set<int>::iterator begin = BinaryTree.lower_bound(lines[endpoints[i].id].x1);
            set<int>::iterator end = BinaryTree.upper_bound(lines[endpoints[i].id].x2);
            cnt += distance(begin, end);
        }
    }
    cout << cnt << endl;
}
