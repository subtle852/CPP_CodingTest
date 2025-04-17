// 030.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    //int logn = 0;
    //int tempn = n;
    //while (true)
    //{
    //    tempn /= 2;
    //    logn += 1;
    //    
    //    if (tempn == 1)
    //        break;
    //}

    //vector<int> arr;
    //for (size_t i = 0; i < n; i++)
    //{
    //    arr.push_back(i+1);
    //}

    //for (size_t i = 1; i <= logn; i++)
    //{
    //    for (size_t j = 0; j < n; j++)
    //    {
    //        int temp = (arr[j] + 1) / 2;
    //        arr[j] = temp;
    //    }
    //    if (arr[a - 1] == arr[b - 1])
    //    {
    //        answer = i;
    //        break;
    //    }
    //}

    do
    {
        a = (a + 1) / 2;
        b = (b + 1) / 2;

        ++answer;
    } while (a != b);

    return answer;
}

int main()
{
    int n, a, b;
    n = 8;
    a = 4;
    b = 7;

    cout << solution(n, a, b);
}

