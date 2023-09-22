#include "glm/glm.hpp"
#include <iostream>
using namespace std;

double GetDistance(glm::dvec3 p, glm::dvec3 edge[2])
{
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

        double d1 = GetDistance(edge2[0], edge1);
        double d2 = GetDistance(edge2[1], edge1);
        double t = d1 / (d1 + d2);
        glm::dvec3 p = edge2[0] + t * (edge2[1] - edge2[0]);
        printf("intersection:%.10f, %.10f", p.x, p.y);
    }
}
