// 017.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    queue<string> queueCards1;
    queue<string> queueCards2;

    for (auto s : cards1)
    {
        queueCards1.push(s);
    }
    for (auto s : cards2)
    {
        queueCards2.push(s);
    }

    queueCards1.push("XXXXXXX"); // queue.front 접근할 때 비어있는 경우 crash가 나기에 그냥 마지막에 쓰레기 값 하나 넣어논 것
    queueCards2.push("XXXXXXX"); // 물론 front 접근할 때 empty 확인해도 됨


    for (size_t i = 0; i < goal.size(); i++)
    {
        if (i == 0)
        {
            if (queueCards1.front() == goal[i])
            {
                queueCards1.pop();
                continue;
            }
            else
            {
                return "No";
            }
        }

        if (queueCards1.front() == goal[i])
        {
            queueCards1.pop();
            continue;
        }
        else
        {
            if (queueCards2.front() == goal[i])
            {
                queueCards2.pop();
                continue;
            }
            else
            {
                return "No";
            }
        }

    }

    return "Yes";
}

int main()
{
    vector<string> cards1, cards2, goal;
    //cards1 = { "i", "drink", "water" };
    //cards2 = { "want", "to" };
    //goal = { "i" , "want", "to", "drink", "water" };

    cards1 = { "i", "water", "drink" };
    cards2 = { "want", "to" };
    goal = { "i" , "want", "to", "drink", "water" };

    string result = solution(cards1, cards2, goal);
    cout << result;

}
