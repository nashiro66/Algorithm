#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (b > a)
    {
        // a>bとする
        swap(a, b);
    }
    while (true)
    {
        int r = a % b;
        if (r == 0)
        {
            cout << b << endl;
            break;
        }
        a = b;
        b = r;
    }
    return 0;
}
