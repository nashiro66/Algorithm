#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

struct process
{
    string name;
    int time;
};

int main()
{
    int n, q;
    cin >> n >> q;
    queue<process> processes;
    for (int i = 0; i < n; i++)
    {
        process p;
        cin >> p.name;
        cin >> p.time;
        processes.push(p);
    }

    int time = 0;
    while (processes.size() != 0)
    {
        if (q < processes.front().time)
        {
            processes.front().time -= q;
            processes.push(processes.front());
            time += q;
        }
        else
        {
            time += processes.front().time;
            cout << processes.front().name << " " << time << endl;
        }
        processes.pop();
    }
    return 0;
}
