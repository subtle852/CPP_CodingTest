#include <iostream>
#include <stack>
using namespace std;

bool solution(const string& input)
{
    stack<char> s;
    for (size_t i = 0; i < input.size(); i++)
    {
        if (s.empty() == false && s.top() == input[i])
        {
            s.pop();
        }
        else
        {
            s.push(input[i]);
        }
    }

    if (s.empty())
        return true;
    else
        return false;
}

int main()
{
    //string input = "baabaa";
    string input = "cdcd";
    cout << solution(input);

}
