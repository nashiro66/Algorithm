#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
int MDT[16][16]; // マンハッタン距離
int N = 4;
int N2 = 16;

struct Puzzle
{
    int state[16];
    int pos = 0; // 0の位置
    int MD; // マンハッタン距離
    int cost = 0;
    bool operator < (const Puzzle& p) const
    {
        for (int i = 0; i < N2; i++)
        {
            if (state[i] == p.state[i])
            {
                continue;
            }
            return state[i] < p.state[i];
        }
        return false;
    }
};

struct State
{
    Puzzle puzzle;
    int estimated;
    bool operator < (const State& s) const
    {
        return estimated > s.estimated;
    }
};

int GetAllMD(Puzzle p)
{
    int sum = 0;
    for (int i = 0; i < N2; i++)
    {
        if (p.state[i] == N2)
        {
            continue;
        }
        sum += MDT[i][p.state[i] - 1];
    }
    return sum;
}

Puzzle input;
static const int directionX[4] = { -1,0,1,0 };
static const int directionY[4] = { 0,1,0,-1 };

int aster(Puzzle p)
{
    p.MD = GetAllMD(p);
    priority_queue<State> pq;
    State initial;
    initial.puzzle = p;
    initial.estimated = GetAllMD(p);
    pq.push(initial);

    map<Puzzle, bool> visitedList;

    while (!pq.empty())
    {
        State currentState = pq.top();
        Puzzle currentPuzzle = currentState.puzzle;
        visitedList[currentPuzzle] = true;
        pq.pop();
        if (currentPuzzle.MD == 0)
        {
            return currentPuzzle.cost;
        }

        int currentX = currentPuzzle.pos % N;
        int currentY = currentPuzzle.pos / N;
        for (int idx = 0; idx < N; idx++)
        {
            int nextX = currentX + directionX[idx];
            int nextY = currentY + directionY[idx];
            if (nextX < 0 || nextY < 0 || N <= nextX || N <= nextY)
            {
                continue;
            }
            // 次の状態を求める
            Puzzle nextPuzzle = currentPuzzle;
            // nextにある現在の数のMDを計算
            nextPuzzle.MD -= MDT[nextX + nextY * N][nextPuzzle.state[nextX + nextY * N] - 1];
            // currentにある次に来る数のMDを計算
            nextPuzzle.MD += MDT[currentX + currentY * N][nextPuzzle.state[nextX + nextY * N] - 1];
            swap(nextPuzzle.state[currentPuzzle.pos], nextPuzzle.state[nextX + nextY * N]);
            nextPuzzle.pos = nextX + nextY * N;
            if (!visitedList[nextPuzzle])
            {
                nextPuzzle.cost++;
                State newState;
                newState.puzzle = nextPuzzle;
                newState.estimated = currentPuzzle.cost + currentPuzzle.MD;
                pq.push(newState);
            }
        }
    }
    return 0;
}

int main()
{
    for (int i = 0; i < N2; i++)
    {
        for (int j = 0; j < N2; j++)
        {
            // iからjまでのマンハッタン距離　y+x
            MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N);
        }
    }

    for (int i = 0; i < N2; i++)
    {
        int x;
        cin >> x;
        input.state[i] = x;
        if (input.state[i] == 0)
        {
            input.pos = i;
            input.state[i] = N2;
        }
    }

    auto ans = aster(input);
    cout << ans << endl;
    return 0;
}
