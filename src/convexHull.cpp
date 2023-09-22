#include <iostream>
#include <sstream>
#include <glm/glm.hpp>
#include <vector>
#include <algorithm>
using namespace std;

struct pos
{
    double x, y;
    bool operator <(const pos& p) const
    {
        if (p.x == x)
        {
            return p.y > y;
        }
        else
        {
            return p.x > x;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<pos> polygon;
    polygon.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> polygon[i].x >> polygon[i].y;
    }
    sort(polygon.begin(), polygon.end());

    vector<pos> upper;
    upper.push_back(polygon[0]);
    upper.push_back(polygon[1]);

    for (int i = 2; i < polygon.size(); i++)
    {
        // 凸包の上部分
        for (int j = upper.size() - 1; 1 <= j; j--)
        {
            glm::vec3 v1 = glm::vec3(upper[j - 1].x - upper[j].x, upper[j - 1].y - upper[j].y, 0);
            glm::vec3 v2 = glm::vec3(polygon[i].x - upper[j].x, polygon[i].y - upper[j].y, 0);
            if (glm::cross(v1, v2).z < 0)
            {
                upper.pop_back();
            }
        }
        upper.push_back(polygon[i]);
    }

    vector<pos> lower;
    lower.push_back(polygon[polygon.size() - 1]);
    lower.push_back(polygon[polygon.size() - 2]);
    for (int i = polygon.size() - 3; 0 <= i; i--)
    {
        // 凸包の下部分
        for (int j = lower.size() - 1; 1 <= j; j--)
        {
            glm::vec3 v1 = glm::vec3(lower[j - 1].x - lower[j].x, lower[j - 1].y - lower[j].y, 0);
            glm::vec3 v2 = glm::vec3(polygon[i].x - lower[j].x, polygon[i].y - lower[j].y, 0);
            if (glm::cross(v1, v2).z < 0)
            {
                lower.pop_back();
            }
        }
        lower.push_back(polygon[i]);
    }
    for (int i = lower.size() - 1; 1 <= i; i--)
    {
        cout << lower[i].x << " " << lower[i].y << endl;
    }
    for (int i = upper.size() - 1; 1 <= i; i--)
    {
        cout << upper[i].x << " " << upper[i].y << endl;
    }

}
