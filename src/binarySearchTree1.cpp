#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct Node
{
    Node* left = nullptr;
    Node* right = nullptr;
    int num = -1;
};
Node* root = nullptr;

void Insert(int insertNum)
{
    Node* currentNode = root;
    if (root == nullptr)
    {
        root = new Node;
        root->num = insertNum;
        return;
    }
    while (true)
    {
        if (insertNum < currentNode->num)
        {
            if (currentNode->left == nullptr)
            {
                currentNode->left = new Node;
                currentNode->left->num = insertNum;
                break;
            }
            else
            {
                currentNode = currentNode->left;
            }
        }
        else
        {
            if (currentNode->right == nullptr)
            {
                currentNode->right = new Node;
                currentNode->right->num = insertNum;
                break;
            }
            else
            {
                currentNode = currentNode->right;
            }
        }
    }
}

void PreOrder(Node* node)
{
    cout << " " << node->num;
    if (node->left != nullptr)
    {
        PreOrder(node->left);
    }
    if (node->right != nullptr)
    {
        PreOrder(node->right);
    }
}

void InOrder(Node* node)
{
    if (node->left != nullptr)
    {
        InOrder(node->left);
    }
    cout << " " << node->num;
    if (node->right != nullptr)
    {
        InOrder(node->right);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "insert")
        {
            int num;
            cin >> num;
            Insert(num);
        }
        else if (s == "print")
        {
            InOrder(root);
            cout << endl;
            PreOrder(root);
            cout << endl;

        }
    }
}
