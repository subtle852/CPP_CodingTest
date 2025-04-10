// 016.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> result = { 0 };

    vector<int> releaseDate(progresses.size(), 0);
    for (size_t i = 0; i < releaseDate.size(); i++) // 배포가능일 계산
    {
        releaseDate[i] = ceil((100.0 - progresses[i]) / speeds[i]); // ceil로 소수점 반올림을 하는 경우 double이나 float형으로 작성 필요
    }

    int count = 0;
    int currentMaxDate = 0;
    for (size_t i = 0; i < progresses.size(); i++) // 배포가능일 계산
    {
        if (i == 0)
        {
            result.back() += 1;
            continue;
        }

        if (releaseDate[currentMaxDate] < releaseDate[i])
        {
            result.push_back(1);
            currentMaxDate = i;
        }
        else
        {
            result.back() += 1;
        }
    }
    return result;
}

int main()
{
    vector<int> progresses;
    vector<int> speeds;

    progresses = { 93, 30, 55 };
    speeds = { 1, 30, 5 };

    //progresses = { 95, 90, 99, 99, 80, 99 };
    //speeds = { 1, 1, 1, 1, 1, 1 };

    vector<int> result = solution(progresses, speeds);
    for (auto i : result)
    {
        cout << i << " ";
    }
}

