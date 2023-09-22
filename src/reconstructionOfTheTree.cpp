#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int pos = 0;
vector<int>Pre;
vector<int>In;
vector<int> Post;

void Reconstruction(int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int root = Pre[pos++];
    int m = distance(In.begin(), find(In.begin(), In.end(), root));
    Reconstruction(left, m);
    Reconstruction(m + 1, right);
    Post.push_back(root);
}

int main()
{
    cin >> n;

    Pre.resize(n);
    In.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Pre[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> In[i];
    }

    Reconstruction(0, n);
    for (int i = 0; i < n; i++)
    {
        cout << Post[i];
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}
