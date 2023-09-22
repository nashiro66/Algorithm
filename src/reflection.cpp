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
        glm::dvec2 ptox = glm::dvec2(2 * (-top.x + proj.x - start.x), 2 * (-top.y + proj.y - start.y));
        glm::dvec2 x = p + ptox;
        printf("refrection:%.10f, %.10f\n", x.x, x.y);
    }
}
