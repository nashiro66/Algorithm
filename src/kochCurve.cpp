#include <iostream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;

int n;
void Koch(double startX, double startY, double endX, double endY, int count)
{
    if (count == n)
    {
        return;
    }
    double sX = startX + (endX - startX) / 3.0;
    double sY = startY + (endY - startY) / 3.0;
    double tX = endX - (endX - startX) / 3.0;
    double tY = endY - (endY - startY) / 3.0;
    double uX = sX + ((tX - sX) / 2.0 - (tY - sY) * sqrt(3) / 2.0);
    double uY = sY + ((tY - sY) / 2.0 + (tX - sX) * sqrt(3) / 2.0);

    Koch(startX, startY, sX, sY, count + 1);
    printf("%.8f %.8f\n", sX, sY);
    Koch(sX, sY, uX, uY, count + 1);
    printf("%.8f %.8f\n", uX, uY);
    Koch(uX, uY, tX, tY, count + 1);
    printf("%.8f %.8f\n", tX, tY);
    Koch(tX, tY, endX, endY, count + 1);

}

int main()
{
    cin >> n;
    int count = 0;
    printf("%.8f %.8f\n", 0.0, 0.0);
    Koch(0.0, 0.0, 100.0, 0.0, count);
    printf("%.8f %.8f\n", 100.0, 0.0);
    return 0;
}
