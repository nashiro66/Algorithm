#include "glm/glm.hpp"
#include <iostream>
using namespace std;

int isCCW(glm::vec3 edge1, glm::vec3 edge2)
{
    if (glm::cross(edge1, edge2).z > 0)
    {
        return 1;
    }
    else if (glm::cross(edge1, edge2).z < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

double GetDistance(glm::dvec3 p, glm::dvec3 edge[2])
{
    if(glm::dot(p-edge[0], edge[1]-edge[0])<0)
    {
        return glm::length(p - edge[0]);
    }
    if(glm::dot(p-edge[1], edge[0]-edge[1])<0)
    {
        return glm::length(p - edge[1]);
    }
    double area = glm::abs(glm::cross(edge[1] - edge[0], p - edge[0]).z);
    double len = area / glm::length(edge[1] - edge[0]);
    return len;
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
        double ans = 0;
        if (isCCW(edge1[1] - edge1[0], edge2[0] - edge1[0]) * isCCW(edge1[1] - edge1[0], edge2[1] - edge1[0]) <= 0 &&
            isCCW(edge2[1] - edge2[0], edge1[0] - edge2[0]) * isCCW(edge2[1] - edge2[0], edge1[1] - edge2[0]) <= 0)
        {
            // intersection
            ans = 0;
        }
        else
        {
            ans = min(GetDistance(edge2[0], edge1), GetDistance(edge2[1], edge1));
        }
        printf("distance:%.10f\n", ans);
    }
}
