#include "glm/glm.hpp"
#include <iostream>
using namespace std;

int isCCW(glm::vec3 p0p1, glm::vec3 p0p2)
{
    if (glm::cross(p0p1, p0p2).z > 0)
    {
        return 1;
    }
    if (glm::cross(p0p1, p0p2).z < 0)
    {
        return -1;
    }
    return 0;
}

void main()
{
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        glm::dvec3 edge1[2];
        cin >> edge1[0].x >> edge1[0].y;
        cin >> edge1[1].x >> edge1[1].y;

        glm::dvec3 edge2[2];
        cin >> edge2[0].x >> edge2[0].y;
        cin >> edge2[1].x >> edge2[1].y;

        if (isCCW(edge1[1] - edge1[0], edge2[0] - edge1[0]) * isCCW(edge1[1] - edge1[0], edge2[1] - edge1[0]) <= 0 &&
            isCCW(edge2[1] - edge2[0], edge1[0] - edge2[0]) * isCCW(edge2[1] - edge2[0], edge1[1] - edge2[0]) <= 0)
        {
            printf("1\n");
        }
        else
        {
            printf("0");
        }
    }
}
