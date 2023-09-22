#include <iostream>
#include <sstream>
#include <glm/glm.hpp>
using namespace std;
long long INF = (1 << 30);

int main()
{
    glm::dvec2 center1;
    double radius1;
    cin >> center1.x >> center1.y >> radius1;
    glm::dvec2 center2;
    double radius2;
    cin >> center2.x >> center2.y >> radius2;

    glm::dvec2 x = center2 - center1;
    double d = x.length();
    double cosA = (radius1 * radius1 + d * d - radius2 * radius2) / (2 * radius1 * d);
    double sinA = sqrt(1 - cosA * cosA);
    glm::dvec2 x1 = center1 + glm::dvec2(x.x * cosA - x.y * sinA, x.x * sinA + x.y * cosA);
    sinA = -sinA;
    glm::dvec2 x2 = center1 + glm::dvec2(x.x * cosA - x.y * sinA, x.x * sinA + x.y * cosA);
    if (x1.x < x2.x)
    {
        printf("%.8f %.8f", x1.x, x1.y);
        printf(" %.8f %.8f", x2.x, x2.y);
    }
    else if (x1.x == x2.x)
    {
        if (x1.y < x2.y)
        {
            printf("%.8f %.8f", x1.x, x1.y);
            printf(" %.8f %.8f", x2.x, x2.y);
        }
        else
        {
            printf("%.8f %.8f", x2.x, x2.y);
            printf(" %.8f %.8f", x1.x, x1.y);
        }
    }
    else
    {
        printf("%.8f %.8f", x2.x, x2.y);
        printf(" %.8f %.8f", x1.x, x1.y);
    }

}
