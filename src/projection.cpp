#include "glm/glm.hpp"
#include <iostream>
using namespace std;

void main()
{
    glm::dvec2 start;
    cin >> start.x >> start.y;
    glm::dvec2 end;
    cin >> end.x >> end.y;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        glm::dvec2 p;
        cin >> p.x >> p.y;
        glm::dvec2 line = end - start;
        glm::dvec2 top = p - start;
        double len = glm::dot(line, top) / glm::length(line);
        glm::dvec2 proj = glm::dvec2(start.x + len * glm::normalize(line).x, start.y + len * glm::normalize(line).y);
        printf("proj:%.10f, %.10f\n", proj.x, proj.y);
    }
}
