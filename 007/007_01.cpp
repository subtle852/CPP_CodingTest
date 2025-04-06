#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

int changeOppositeDirection(int inputDirection)
{
    return (inputDirection + 2) % 4;
}

int solution(const string& input)
{
    bool visited[11][11][4] = { false, };

    int count = 0;
    pair<int, int> curPos = { 5, 5 };

    int dx[4] = {-1, 0, +1, 0};// U L D R
    int dy[4] = {0, -1, 0, +1};

    for (size_t i = 0; i < input.size(); i++)
    {
        pair<int, int> nxtPos;
        int nxtDir = 0;

        switch (input[i])
        {
        case 'U':
            nxtPos.first = curPos.first + dx[0];
            nxtPos.second = curPos.second + dy[0];
            nxtDir = 0;
            break;
        case 'L':
            nxtPos.first = curPos.first + dx[1];
            nxtPos.second = curPos.second + dy[1];
            nxtDir = 1;
            break;
        case 'D':
            nxtPos.first = curPos.first + dx[2];
            nxtPos.second = curPos.second + dy[2];
            nxtDir = 2;
            break;
        case 'R':
            nxtPos.first = curPos.first + dx[3];
            nxtPos.second = curPos.second + dy[3];
            nxtDir = 3;
            break;
        }

        // 초과하면 예외
        if (0 > nxtPos.first || nxtPos.first > 10 || 0 > nxtPos.second || nxtPos.second > 10)
        {
            continue;
        }

        // 중복되면 예외
        if (visited[curPos.first][curPos.second][nxtDir] == true)
        {
            curPos = nxtPos; // 중복되더라도 위치는 변경해야 함
            continue;
        }
        else
        {
            int a = 100;
        }

        visited[curPos.first][curPos.second][nxtDir] = true;
        visited[nxtPos.first][nxtPos.second][changeOppositeDirection(nxtDir)] = true; // 반대 방향도 true
        count++;
        curPos = nxtPos;
    }


    return count;

}

int main()
{
    string dirs = "ULURRDLLU";
    //string dirs = "LULLLLLLU";
    //string dirs = "LRLRLR";

    int result = solution(dirs);
    cout << result;

}

// 3차원 배열은 참신하네요
