#include "glm/glm.hpp"
#include <iostream>
using namespace std;

void isCCW(glm::vec3 p0p1, glm::vec3 p0p2)
{
    if (glm::cross(p0p1, p0p2).z > 0)
    {
        printf("COUNTER_CLOCKWISE\n");
    }
    else if (glm::cross(p0p1, p0p2).z < 0)
    {
        printf("CLOCKWISE\n");
    }
    else
    {
        if (glm::normalize(p0p1) == -glm::normalize(p0p2))
        {
            printf("ONLINE_BACK\n");
        }
        else if (glm::length(p0p1) < glm::length(p0p2))
        {
            printf("ONLINE_FRONT\n");
        }
        else if (glm::length(p0p2) < glm::length(p0p1))
        {
            printf("ON_SEGMENT\n");
        }
    }
}


void main()
{
    glm::dvec3 edge[2];
    cin >> edge[0].x >> edge[0].y;
    cin >> edge[1].x >> edge[1].y;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {

        glm::dvec3 p;
        cin >> p.x >> p.y;
        isCCW(edge[1] - edge[0], p - edge[0]);
    }
}
