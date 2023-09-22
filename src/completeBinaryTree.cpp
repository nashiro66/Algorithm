#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct Node
{
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    long long num = -20000000000;
};
int main()
{
    cin >> n;
    vector<Node> nodes;
    nodes.resize(n + 1);
    Node* parent = nullptr;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        nodes[i].num = num;
        if (i == 1) continue;

        parent = &nodes[i / 2];
        if (parent != nullptr)
        {
            nodes[i].parent = parent;
            if (i % 2 == 0)
            {
                parent->left = &nodes[i];
            }
            else
            {
                parent->right = &nodes[i];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "node " << i << ": key = " << nodes[i].num << ", ";
        if (nodes[i].parent != nullptr)
        {
            cout << "parent key = " << nodes[i].parent->num << ", ";
        }
        if (nodes[i].left != nullptr)
        {
            cout << "left key = " << nodes[i].left->num << ", ";
        }
        if (nodes[i].right != nullptr)
        {
            cout << "right key = " << nodes[i].right->num << ", ";
        }
        cout << endl;
    }
}
