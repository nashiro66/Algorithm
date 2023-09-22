#include <iostream>
#include <sstream>
#include <glm/glm.hpp>
#include <vector>
using namespace std;
long long INF = (1 << 30);


int main()
{
    int n;
    cin >> n;
    vector<glm::vec2> polygon;
    polygon.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> polygon[i].x >> polygon[i].y;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        glm::vec2 p;
        cin >> p.x >> p.y;
        bool x = false;
        for (int j = 0; j < n; j++)
        {
            glm::vec2 A = polygon[j] - p;
            glm::vec2 B = polygon[(j + 1) % n] - p;
            if (glm::cross(glm::vec3(A.x, A.y, 0), glm::vec3(B.x, B.y, 0)).z == 0.0 && glm::dot(glm::vec3(A.x, A.y, 0), glm::vec3(B.x, B.y, 0)) < 0.0)
            {
                cout << 1 << endl;
                break;
            }
            if (A.y > B.y)
            {
                swap(A, B);
            }
            if (A.y <= 0 && 0 < B.y && glm::cross(glm::vec3(A.x, A.y, 0), glm::vec3(B.x, B.y, 0)).z > 0)
            {
                // 偶数回のときに外, 奇数回のときに内
                x = !x;
            }
        }
        if (x == true)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}
