#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
int N = 8;

struct Puzzle
{
    int state[9];
    int pos = 0; // 0の位置
    int distance = 0;
    bool operator < (const Puzzle& p) const
    {
        for (int i = 0; i < 9; i++)
        {
            if (state[i] == p.state[i])
            {
                continue;
            }
            return state[i] > p.state[i];
        }
        return false;
    }
};

Puzzle input;
map<Puzzle, bool> mapList; // 既に調べた状態か
static const int directionX[4] = { -1,0,1,0 };
static const int directionY[4] = { 0,1,0,-1 };

int bfs(Puzzle p)
{
    queue<Puzzle> q;
    q.push(p);
    mapList[p] = true;

    while (!q.empty())
    {
        Puzzle currentState = q.front();
        q.pop();

        // 答えか確認
        bool isAns = true;
        for (int i = 0; i < 9; i++)
        {
            if (currentState.state[i] != i + 1)
            {
                isAns = false;
            }
        }
        if (isAns)
        {
            return currentState.distance;
        }

        int currentX = currentState.pos % 3;
        int currentY = currentState.pos / 3;
        for (int idx = 0; idx < 4; idx++)
        {
            int tx = currentX + directionX[idx];
            int ty = currentY + directionY[idx];
            if (tx < 0 || ty < 0 || 3 <= tx || 3 <= ty)
            {
                continue;
            }
            // 次の状態を求める
            Puzzle nextState = currentState;
            swap(nextState.state[currentState.pos], nextState.state[tx + ty * 3]);
            nextState.pos = tx + ty * 3;
            if (!mapList[nextState])
            {
                mapList[nextState] = true;
                nextState.distance = currentState.distance + 1;
                q.push(nextState);
            }
        }
    }
    return 0;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        int x;
        cin >> x;
        input.state[i] = x;
        if (input.state[i] == 0)
        {
            input.pos = i;
            input.state[i] = 9;
        }
    }

    auto ans = bfs(input);
    cout << ans << endl;
}
