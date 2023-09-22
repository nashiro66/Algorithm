#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
unsigned long long M = 1000000007;

unsigned long long  Pow(unsigned long long m, unsigned long long n)
{
    if (n == 0)
        return 1;

    unsigned long long tmp = Pow(m, n / 2);

    if (n % 2 == 0)
        return (tmp * tmp) % M;
    else
        return ((tmp * tmp) % M * m) % M;
}

int main()
{
    int m, n;
    cin >> m >> n;
    unsigned long long ans = Pow(m, n);
    cout << ans << endl;
    return 0;
}
