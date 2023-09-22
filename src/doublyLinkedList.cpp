#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

class doubleList
{
public:
    void insert(int n)
    {
        nums.push_front(n);
    }

    void del(int n)
    {
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (*it == n)
            {
                nums.erase(it);
                break;
            }
        }
    }

    void deleteFirst()
    {
        nums.pop_front();
    }

    void deleteLast()
    {
        nums.pop_back();
    }

    void print()
    {
        for (int i = 0; !nums.empty(); i++)
        {
            cout << nums.front();
            nums.pop_front();
            if (nums.size() != 0)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

private:
    list<int> nums;
};

int main()
{
    int n;
    cin >> n;
    doubleList list;
    for (int i = 0; i < n; i++)
    {
        char order[20];
        int n;
        scanf("%s", &order);
        string s(order);
        if (s == "insert")
        {
            scanf("%d", &n);
            list.insert(n);
        }
        else if (s == "delete")
        {
            scanf("%d", &n);
            list.del(n);
        }
        else if (s == "deleteFirst")
        {
            list.deleteFirst();
        }
        else if (s == "deleteLast")
        {
            list.deleteLast();
        }
    }
    list.print();

    return 0;
}
