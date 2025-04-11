// 018.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <unordered_set>

using namespace std;

bool solution(vector<int> arr, int target)
{
    unordered_set<int> uset;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= target)
            break;

        uset.insert(arr[i]);
    }

    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= target)
            break;

        int another = target - arr[i];
        auto anotherIt = uset.find(another);
        if (anotherIt != uset.end()) // 찾은 경우
        {
            if (*anotherIt == arr[i])
            {
                continue;
            }

            return true;
        }
    }

    return false;
}

int main()
{
    vector<int> arr;
    int target;
    bool result;

    arr = { 1, 2, 3, 4, 8 };
    target = 6;

    arr = { 2, 3, 5, 9 };
    target = 10;

    result = solution(arr, target);
    cout << result;

}
