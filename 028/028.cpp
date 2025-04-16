// 028.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Front(vector<int> nodes, int pos, vector<string>& answer)
{
    if (nodes.size() <= pos)
        return;

    answer[0] += to_string(nodes[pos]);
    Front(nodes, pos * 2 + 1, answer);
    Front(nodes, pos * 2 + 2, answer);
}

void Middle(vector<int> nodes, int pos, vector<string>& answer)
{
    if (nodes.size() <= pos)
        return;

    Middle(nodes, pos * 2 + 1, answer);
    answer[1] += to_string(nodes[pos]);
    Middle(nodes, pos * 2 + 2, answer);
}

void Back(vector<int> nodes, int pos, vector<string>& answer)
{
    if (nodes.size() <= pos)
        return;

    Back(nodes, pos * 2 + 1, answer);
    Back(nodes, pos * 2 + 2, answer);
    answer[2] += to_string(nodes[pos]);
}

vector<string> solution(vector<int> nodes)
{
    vector<string> answer;
    answer.resize(3);

    // 전위
    Front(nodes, 0, answer);

    // 중위
    Middle(nodes, 0, answer);

    // 후위
    Back(nodes, 0, answer);

    return answer;
}

int main()
{
    vector<int> nodes = { 1, 2, 3, 4, 5, 6, 7 };
    vector<string> result;
    result = solution(nodes);
    for (auto s : result)
        cout << s << " ";
}
