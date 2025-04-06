#include <iostream>
#include <stack>
using namespace std;

bool solution(const string& InString)
{
    stack<char> check;

    for (size_t i = 0; i < InString.size(); i++)
    {
        if (check.empty())
        {
            check.push(InString[i]);
            continue;
        }

        if (check.top() == '(' && InString[i] == ')')
        {
            check.pop();
            continue;
        }

        check.push(InString[i]);
    }

    if (check.empty())
        return true;
    else
        return false;
}

int main()
{
    string s = { '(', '(', ')', ')', '(', ')' };
    //string s = { '(', '(','(', ')', ')', '(', ')' };

    bool result = solution(s);
    cout << result;

}
