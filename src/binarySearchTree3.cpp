#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct Node
{
    Node* left = nullptr;
    Node* right = nullptr;
    long long num = -20000000000;
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

void Find(int num)
{
    Node* currentNode = root;
    while (true)
    {
        if (currentNode == nullptr)
        {
            cout << "no" << endl;
            return;
        }
        if (num == currentNode->num)
        {
            cout << "yes" << endl;
            return;
        }
        else if (num < currentNode->num)
        {
            currentNode = currentNode->left;
        }
        else
        {
            currentNode = currentNode->right;
        }
    }
}

void Delete(int num)
{
    Node* currentNode = root;
    Node* parentNode = nullptr;
    while (true)
    {
        if (currentNode == nullptr)
        {
            return;
        }
        if (num == currentNode->num)
        {
            if (currentNode->left == nullptr && currentNode->right == nullptr)
            {
                // 子を持たない場合
                if (parentNode->left == currentNode)
                {
                    parentNode->left = nullptr;
                }
                else
                {
                    parentNode->right = nullptr;
                }
                delete currentNode;
                break;
            }
            else if (currentNode->right == nullptr)
            {
                // 1つ左の子を持つ場合
                if (parentNode->left == currentNode)
                {
                    parentNode->left = currentNode->left;
                }
                else
                {
                    parentNode->right = currentNode->left;
                }
                delete currentNode;
                break;
            }
            else if (currentNode->left == nullptr)
            {
                // 1つ右の子を持つ場合
                if (parentNode->left == currentNode)
                {
                    parentNode->left = currentNode->right;
                }
                else
                {
                    parentNode->right = currentNode->right;
                }
                delete currentNode;
                break;
            }
            else if (currentNode->left != nullptr && currentNode->right != nullptr)
            {
                // 2つの子を持つ場合
                Node* currentSearchNode = currentNode->right;
                Node* currentSearchNodeParent = currentNode;
                while (true)
                {
                    if (currentSearchNode->left != nullptr)
                    {
                        currentSearchNodeParent = currentSearchNode;
                        currentSearchNode = currentSearchNode->left;
                    }
                    else if (currentSearchNode->left == nullptr)
                    {
                        break;
                    }
                }
                if (parentNode->left == currentNode)
                {
                    parentNode->left = currentSearchNode;
                    if (currentSearchNode != currentNode->right)
                    {
                        currentSearchNode->right = currentNode->right;
                    }
                    currentSearchNode->left = currentNode->left;
                    currentSearchNodeParent->left = nullptr;

                }
                else
                {
                    parentNode->right = currentSearchNode;
                    if (currentSearchNode != currentNode->right)
                    {
                        currentSearchNode->right = currentNode->right;
                    }
                    currentSearchNode->left = currentNode->left;
                    currentSearchNodeParent->left = nullptr;
                }
                delete currentNode;
                break;
            }
            return;
        }
        else if (num < currentNode->num)
        {
            parentNode = currentNode;
            currentNode = currentNode->left;
        }
        else
        {
            parentNode = currentNode;
            currentNode = currentNode->right;
        }
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
        else if (s == "find")
        {
            int num;
            cin >> num;
            Find(num);
        }
        else if (s == "delete")
        {
            int num;
            cin >> num;
            Delete(num);
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
