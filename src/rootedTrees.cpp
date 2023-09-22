#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
enum type
{
    root,
    internalNode,
    leaf
};

struct node
{
    vector<int> children;
    int depth = 0;
    int parent = -1;
    type t;
};

void Depth(vector<node>& nodes, int currentIndex)
{
    if (nodes[currentIndex].t == leaf)
    {
        nodes[currentIndex].depth = nodes[nodes[currentIndex].parent].depth + 1;
        return;
    }
    if (nodes[currentIndex].t != root)
    {
        nodes[currentIndex].depth = nodes[nodes[currentIndex].parent].depth + 1;
    }
    for (int i = 0; i < nodes[currentIndex].children.size(); i++)
    {
        Depth(nodes, nodes[currentIndex].children[i]);
    }
}

int main()
{
    cin >> n;
    vector<int>nums;
    nums.resize(n);
    vector<node>nodes;
    nodes.resize(n);
    for (int i = 0; i < n; i++)
    {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; j++)
        {
            int child;
            cin >> child;
            nodes[id].children.push_back(child);
            nodes[child].parent = id;
        }
    }

    int rootIdx = -1;
    for (int i = 0; i < n; i++)
    {
        if (nodes[i].parent == -1)
        {
            nodes[i].depth = 0;
            nodes[i].t = root;
            rootIdx = i;
        }
        else
        {
            if (nodes[i].children.size() == 0)
            {
                nodes[i].t = leaf;
            }
            else
            {
                nodes[i].t = internalNode;
            }
        }
    }

    Depth(nodes, rootIdx);

    // output
    for (int i = 0; i < n; i++)
    {
        cout << "node " << i << ": parent = " << nodes[i].parent << ", depth = " << nodes[i].depth << ", ";
        if (nodes[i].t == root)
        {
            cout << "root, ";
        }
        else if (nodes[i].t == internalNode)
        {
            cout << "internal node, ";
        }
        else
        {
            cout << "leaf, ";
        }
        cout << "[";
        for (int j = 0; j < nodes[i].children.size(); j++)
        {
            if (j != 0)
            {
                cout << ", ";
            }
            cout << nodes[i].children[j];
        }
        cout << "]";
        cout << endl;
    }
}
