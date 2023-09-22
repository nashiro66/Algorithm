#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Matrix
{
    int row;
    int col;
};

int main()
{
    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        bool isPrime = true;
        for (int j = 2; j <= sqrt(num); j++)
        {
            if (num % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
