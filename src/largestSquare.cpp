#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct Rectangle
{
public:
    int height, pos;
};

int H, W;
vector<vector<int> > graph;
vector<vector<int> > hist;
int maxv;

int GetLargestRectangle(int h)
{
    stack<Rectangle> s;
    for (int j = 0; j <= W; j++)
    {
        Rectangle rectangle;
        rectangle.height = hist[h][j];
        rectangle.pos = j;

        if (s.empty())
        {
            s.push(rectangle);
        }
        else
        {
            if (s.top().height < rectangle.height)
            {
                s.push(rectangle);
            }
            else if (s.top().height > rectangle.height)
            {
                int target = j;
                while (!s.empty() && s.top().height >= rectangle.height)
                {
                    Rectangle pre = s.top();
                    s.pop();
                    int area = pre.height * (j - pre.pos);
                    maxv = max(maxv, area);
                    target = pre.pos;
                }
                rectangle.pos = target;
                s.push(rectangle);
            }
        }
    }
    return maxv;
}

int main()
{

    cin >> H >> W;
    graph.resize(H);
    hist.resize(H);
    for (int i = 0; i < H; i++)
    {
        graph[i].resize(W);
        hist[i].resize(W + 1, 0);
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> graph[i][j];
        }
    }

    // init
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (graph[i][j] == 1)
            {
                hist[i][j] = 0;
            }
            else if (i != 0)
            {
                hist[i][j] = hist[i - 1][j] + 1;
            }
            else
            {
                hist[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < H; i++)
    {
        maxv = max(maxv, GetLargestRectangle(i));
    }

    cout << maxv << endl;
    return 0;
}
