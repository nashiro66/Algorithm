#include <glm/glm.hpp>
#include <iostream>
using namespace std;

void main()
{
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        glm::vec2 start1;
        cin >> start1.x >> start1.y;
        glm::vec2 end1;
        cin >> end1.x >> end1.y;
        glm::vec2 start2;
        cin >> start2.x >> start2.y;
        glm::vec2 end2;
        cin >> end2.x >> end2.y;
        if(glm::normalize(end1-start1)==glm::normalize(end2-start2))
        {
            printf("2\n");
        }
        else if(glm::dot(end1-start1,end2-start2)==0)
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
    }
}
