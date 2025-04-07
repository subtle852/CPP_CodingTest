// 009.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
using namespace std;

string output;

const string& solution(int input)
{
    stack<int> s;

    while(true)
    {
        if (input < 2)
        {
            s.push(input);
            break;
        }

        int temp;
        temp = input % 2;
        s.push(temp);

        input /= 2;
    }

    while (s.empty() == false)
    {
        int curValue = s.top();
        s.pop();

        switch (curValue)
        {
        case 0:
            output += '0';
            break;
        case 1:
            output += '1';
            break;
        }
    }

    return output;
}

int main()
{
    //int decimal = 10;
    //int decimal = 27;
    int decimal = 12345;
    string result;

    result = solution(decimal);

    cout << result;

}
