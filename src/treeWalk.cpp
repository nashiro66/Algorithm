#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct node
{
    int left = -1;
    int right = -1;
    int parent = -1;
};

void PreOrder(vector<node> nodes, int currentNode)
{
    cout << " " << currentNode;
    if (nodes[currentNode].left != -1)
    {
        PreOrder(nodes, nodes[currentNode].left);
    }
    if (nodes[currentNode].right != -1)
    {
        PreOrder(nodes, nodes[currentNode].right);
    }
}

void InOrder(vector<node> nodes, int currentNode)
{
    if (nodes[currentNode].left != -1)
    {
        InOrder(nodes, nodes[currentNode].left);
    }
    cout << " " << currentNode;
    if (nodes[currentNode].right != -1)
    {
        InOrder(nodes, nodes[currentNode].right);
    }
}

void PostOrder(vector<node> nodes, int currentNode)
{
    if (nodes[currentNode].left != -1)
    {
        PostOrder(nodes, nodes[currentNode].left);
    }
    if (nodes[currentNode].right != -1)
    {
        PostOrder(nodes, nodes[currentNode].right);
    }
    cout << " " << currentNode;
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
    }

    // output
    int root = 0;
    while (nodes[root].parent != -1)
    {
        root = nodes[root].parent;
    }
    cout << "Preorder" << endl;
    PreOrder(nodes, root);
    cout << endl;
    cout << "Inorder" << endl;
    InOrder(nodes, root);
    cout << endl;
    cout << "Postorder" << endl;
    PostOrder(nodes, root);
    cout << endl;
}
