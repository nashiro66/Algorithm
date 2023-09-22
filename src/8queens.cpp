#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int N = 8;

vector<vector<bool> > X;
vector<int> row;
vector<int> col;
vector<int> dpos;
vector<int>dneg;

void Recursive(int i)
{
    if (i == N)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (X[i][j])
                {
                    if (row[i] != j)
                    {
                        return;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (row[i] == j)
                {
                    cout << "Q";
                }
                else
                {
                    cout << ".";
                }
            }
            cout << endl;
        }
        return;
    }
    for (int j = 0; j < N; j++)
    {
        if (col[j] == 1 || dpos[i + j] == 1 || dneg[N + i - j - 1] == 1)
        {
            // 配置できない   
            continue;
        }
        row[i] = j;
        col[j] = 1;
        dpos[i + j] = 1;
        dneg[N + i - j - 1] = 1;
        Recursive(i + 1);
        // 失敗したので取り除く
        row[i] = -1;
        col[j] = -1;
        dpos[i + j] = -1;
        dneg[N + i - j - 1] = -1;
    }
    // 配置に失敗
}

int main()
{
    X.resize(N);
    for (int i = 0; i < N; i++)
    {
        X[i].resize(N);
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        X[x][y] = true;
    }

    row.resize(N, -1);
    col.resize(N, -1);
    dpos.resize(N * 2 - 1, -1);
    dneg.resize(N * 2 - 1, -1);

    Recursive(0);
}
