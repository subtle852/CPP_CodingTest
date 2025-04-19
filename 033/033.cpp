// 033.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> parent;
vector<int> r;

int Find(int number)
{
    if (parent[number] == -1)
    {
        parent[number] = number;
    }

    if (parent[number] != number)
    {
        parent[number] = Find(parent[number]);
    }
    return parent[number];
}

void Union(int first, int second)
{
    int rootF = Find(first);
    int rootS = Find(second);

    // find를 하면서 경로압축이 진행
    
    if (r[first] > r[second])
    {
        parent[second] = first; // 큰 쪽으로 합쳐줄 때는 rank가 늘어나지 않음

    }
    else if (r[first] < r[second])
    {
        parent[first] = second; // 큰 쪽으로 합쳐줄 때는 rank가 늘어나지 않음
    }
    else // 랭크 동일
    {
        parent[second] = first;
        r[first]++; // 랭크가 동일한 경우에 한쪽으로 합쳐줄 때는 rank++
    }

}

vector<bool> solution(int k, vector<vector<char>> operations)
{
    vector<bool> answer;

    for (size_t i = 0; i < operations.size(); i++)
    {
        char firstNumberC = *(++operations[i].begin());
        int firstNumber = firstNumberC - '0';

        char secondNumberC = *(++++operations[i].begin());
        int secondNumber = secondNumberC - '0';

        if (*operations[i].begin() == 'f')
        {
            int rootF = Find(firstNumber);
            int rootS = Find(secondNumber);

            if (rootF == rootS)
                answer.push_back(true);

            else
                answer.push_back(false);

        }
        else
        {
            Union(firstNumber, secondNumber);
        }
    }

    return answer;
}

int main()
{
    int k;
    vector<vector<char>> operations;
    k = 3;
    operations = { {'u', '0', '1'},{'u', '1', '2'},{'f', '0', '2'} };

    k = 4;
    operations = { {'u', '0', '1'},{'u', '2', '3'},{'f', '0', '1'},{'f', '0', '2'} };

    parent.resize(1000, -1);
    r.resize(1000, 0);
    vector<bool> result = solution(k, operations);
    for (auto b : result)
        cout << b;

}
