#include <iostream>
#include <sstream>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define INF 1000000000

class Node
{
public:
    int location = -1;
    int left = -1;
    int right = -1;
};

class Point
{
public:

    Point() {}

    Point(int inputId, int inputX, int inputY)
    {
        id = inputId;
        x = inputX;
        y = inputY;
    }

    bool operator <(const Point& p)const
    {
        return id < p.id;
    }

    int x, y, id;
};

bool lessX(const Point& p1, const Point& p2)
{
    return p1.x < p2.x;
}

bool lessY(const Point& p1, const Point& p2)
{
    return p1.y < p2.y;
}

vector<Point> points;
vector<Node> tree;
int order = 0;

int MakeKDTree(int left, int right, int depth)
{
    if (!(left < right))
    {
        return -1;
    }

    int mid = (left + right) / 2;
    if (depth % 2 == 0)
    {
        sort(points.begin() + left, points.begin() + right, lessX);
    }
    else
    {
        sort(points.begin() + left, points.begin() + right, lessY);
    }

    int treeIndex = order++;
    // nodesにはソートされたデータが入る
    tree[treeIndex].location = mid;
    tree[treeIndex].left = MakeKDTree(left, mid, depth + 1);
    tree[treeIndex].right = MakeKDTree(mid + 1, right, depth + 1);

    return treeIndex;
}

void Find(int v, int sx, int tx, int sy, int ty, int depth, vector<Point>& ans)
{
    int currentX = points[tree[v].location].x;
    int currentY = points[tree[v].location].y;
    if (sx <= currentX && currentX <= tx && sy <= currentY && currentY <= ty)
    {
        // 範囲内に収まっているならansに格納する
        ans.push_back(points[tree[v].location]);
    }

    if (depth % 2 == 0)
    {
        // depthが偶数の時はx方向で探索する
        if (tree[v].left != -1)
        {
            // 左の木を探索する
            if (sx <= currentX)
            {
                Find(tree[v].left, sx, tx, sy, ty, depth + 1, ans);
            }
        }
        if (tree[v].right != -1)
        {
            // 右の木を探索する
            if (currentX <= tx)
            {
                Find(tree[v].right, sx, tx, sy, ty, depth + 1, ans);
            }
        }
    }
    else
    {
        // depthが奇数の時はy方向で探索する
        if (tree[v].left != -1)
        {
            // 左の木を探索する
            if (sy <= currentY)
            {
                Find(tree[v].left, sx, tx, sy, ty, depth + 1, ans);
            }
        }
        if (tree[v].right != -1)
        {
            // 右の木を探索する
            if (currentY <= ty)
            {
                Find(tree[v].right, sx, tx, sy, ty, depth + 1, ans);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int x, y;
    points.resize(n);
    tree.resize(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        points[i] = Point(i, x, y);
    }

    int root = MakeKDTree(0, n, 0);

    int q;
    cin >> q;
    int sx, sy, tx, ty;
    vector<Point> ans;
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
        Find(root, sx, tx, sy, ty, 0, ans);
        sort(ans.begin(), ans.end());
        for (int j = 0; j < ans.size(); j++)
        {
            printf("%d\n", ans[j].id);
        }
        cout << endl;
        ans.clear();
    }
}
