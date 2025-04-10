// 016.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> result = { 0 };

    queue<int> q;
    for (size_t i = 0; i < progresses.size(); i++)
    {
        q.push(i);
    }

    while (q.empty() == false)
    {
        for (size_t i = 0; i < progresses.size(); i++)
        {
            progresses[i] += speeds[i];
        }

        int frontProgressIndex = q.front();
        while (progresses[frontProgressIndex] >= 100)
        {
            q.pop();
            result.back() += 1;

            frontProgressIndex++;
            if (q.empty() == true)
            {
                break;
            }
        }

        if (q.empty() == true)
        {
            break;
        }

        if (result.back() > 0)
        {
            result.push_back(0);
        }
    }


    return result;
}

int main()
{
    vector<int> progresses;
    vector<int> speeds;

    //progresses = { 93, 30, 55 };
    //speeds = { 1, 30, 5 };

    progresses = { 95, 90, 99, 99, 80, 99 };
    speeds = { 1, 1, 1, 1, 1, 1 };

    vector<int> result = solution(progresses, speeds);
    for (auto i : result)
    {
        cout << i << " ";
    }
}

