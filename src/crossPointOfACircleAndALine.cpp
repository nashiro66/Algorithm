#include <iostream>
#include <sstream>
#include <glm/glm.hpp>
using namespace std;
long long INF = (1 << 30);

glm::vec3 GetProjection(glm::dvec3 point, glm::dvec3 edge[2])
{
    glm::dvec3 start2p = point - edge[0];
    glm::dvec3 start2end = edge[1] - edge[0];

    double cos = glm::dot(start2p, start2end) / (glm::length(start2p) * glm::length(start2end));
    double start2x = glm::length(start2p) * cos;
    return edge[0] + start2x * glm::normalize(start2end);
}

double GetDistance(glm::dvec3 p, glm::dvec3 start, glm::dvec3 end)
{
    // 必ず円と交点を持つ
    glm::dvec3 start2p = p - start;
    glm::dvec3 start2end = end - start;
    double area = glm::length(glm::cross(start2p, start2end));
    return area / glm::length(start2end);
}

int main()
{
    glm::dvec3 center;
    double radius;
    cin >> center.x >> center.y >> radius;
    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        glm::dvec3 line[2];
        cin >> line[0].x >> line[0].y;
        cin >> line[1].x >> line[1].y;
        double distance = GetDistance(center, line[0], line[1]);
        double base = glm::sqrt(radius * radius - distance * distance);

        glm::dvec3 proj = GetProjection(center, line);
        glm::dvec3 ans1 = proj + base * glm::normalize(line[1] - line[0]);
        glm::dvec3 ans2 = proj - base * glm::normalize(line[1] - line[0]);
        if (ans1.x < ans2.x)
        {
            printf("%.6f %6f ", ans1.x, ans1.y);
            printf("%.6f %6f\n", ans2.x, ans2.y);
        }
        else
        {
            printf("%.6f %6f ", ans2.x, ans2.y);
            printf("%.6f %6f\n", ans1.x, ans1.y);
        }
    }
}
