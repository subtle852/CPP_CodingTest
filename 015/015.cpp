// 015.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;

int solution(int N, int K)
{
    queue<int> q;
    for (size_t i = 1; i <= N; i++)
    {
        q.push(i);
    }

    int count = 1;

    while (q.size() > 1)
    {
        if (count == K)
        {
            q.pop();
            count = 1;
        }
        else
        {
            int temp = q.front();
            q.pop();
            q.push(temp);

            count++;
        }
    }

    return q.back();

}

int main()
{
    int N, K;
    N = 5;
    K = 2;

    cout << solution(5, 2);
}
