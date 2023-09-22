#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    vector<string> input;
    stringstream ss(s);
    while (ss >> s)
    {
        input.push_back(s);
    }

    stack<int> stack;
    for (int i = 0; i < input.size(); i++)
    {
        int num;
        if (input[i] == "+")
        {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            num = a + b;
            stack.push(num);
        }
        else if (input[i] == "-")
        {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            num = a - b;
            stack.push(num);
        }
        else if (input[i] == "*")
        {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            num = a * b;
            stack.push(num);
        }
        else if (input[i] == "/")
        {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            num = a / b;
            stack.push(num);
        }
        else
        {
            stack.push(stoi(input[i]));
        }
    }

    cout << stack.top() << endl;

    return 0;
}
