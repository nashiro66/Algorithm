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
    int left = -1;
    int right = -1;
    int sibling = -1;
    int depth = 0;
    int parent = -1;
    int degree = 0;
    int height = 0;
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
    if (nodes[currentIndex].left != -1)
    {
        Depth(nodes, nodes[currentIndex].left);
    }
    if (nodes[currentIndex].right != -1)
    {
        Depth(nodes, nodes[currentIndex].right);
    }
    return;
}

void Height(vector<node>& nodes, int currentIndex)
{
    if (nodes[currentIndex].t == leaf)
    {
        nodes[currentIndex].height = 0;
    }
    if (nodes[currentIndex].left != -1)
    {
        nodes[currentIndex].height = max(nodes[currentIndex].height, nodes[nodes[currentIndex].left].height + 1);
    }
    if (nodes[currentIndex].right != -1)
    {
        nodes[currentIndex].height = max(nodes[currentIndex].height, nodes[nodes[currentIndex].right].height + 1);
    }
    if (nodes[currentIndex].t == root)
    {
        return;
    }
    Height(nodes, nodes[currentIndex].parent);
}

int main()
{
    cin >> n;
    vector<node>nodes;
    nodes.resize(n);
    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;
        cin >> nodes[id].left;
        cin >> nodes[id].right;
        if (nodes[id].left != -1)
        {
            nodes[nodes[id].left].parent = id;
        }
        if (nodes[id].right != -1)
        {
            nodes[nodes[id].right].parent = id;
        }
        if (nodes[id].left != -1 && nodes[id].right != -1)
        {
            nodes[nodes[id].left].sibling = nodes[id].right;
            nodes[nodes[id].right].sibling = nodes[id].left;
        }
    }

    int rootIdx = 0;
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
            if (nodes[i].left == -1 && nodes[i].right == -1)
            {
                nodes[i].t = leaf;
            }
            else
            {
                nodes[i].t = internalNode;
            }
        }
        if (nodes[i].left != -1 && nodes[i].right != -1)
        {
            nodes[i].degree = 2;
        }
        else if (nodes[i].left != -1 || nodes[i].right != -1)
        {
            nodes[i].degree = 1;
        }
    }

    Depth(nodes, rootIdx);
    for (int i = 0; i < n; i++)
    {
        if (nodes[i].t == leaf)
        {
            Height(nodes, i);
        }
    }

    // output
    for (int i = 0; i < n; i++)
    {
        cout << "node " << i
            << ": parent = " << nodes[i].parent
            << ", sibling = " << nodes[i].sibling
            << ", degree = " << nodes[i].degree
            << ", depth = " << nodes[i].depth
            << ", height = " << nodes[i].height
            << ", ";

        if (nodes[i].t == root)
        {
            cout << "root";
        }
        else if (nodes[i].t == internalNode)
        {
            cout << "internal node";
        }
        else
        {
            cout << "leaf";
        }
        cout << endl;
    }
}
