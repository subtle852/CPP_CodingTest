// 023.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    unordered_map<string, int> wantUMap;
    for (size_t i = 0; i < want.size(); i++)
    {
        wantUMap[want[i]] = number[i];
    }

    int totalWantCount = 0;
    for (size_t i = 0; i < number.size(); i++)
    {
        totalWantCount += number[i];
    }

    int currentPassCount = 0;
    for (size_t i = 0; i < discount.size(); i++)
    {
        auto it = wantUMap.find(discount[i]);
        if (it != wantUMap.end()) // 찾
        {
            it->second--;
        }

        if (i >= 9) // 10일차 부터
        {
            // 확인
            bool IsPass = true;
            for (auto it = wantUMap.begin(); it != wantUMap.end(); it++)
            {
                if (it->second >= 1)
                {
                    IsPass = false;
                }
            }

            if (IsPass == true)
            {
                currentPassCount++;
            }

            // 앞에꺼 pop == 복구
            int restoreIndex = i - (10 - 1);
            auto it = wantUMap.find(discount[restoreIndex]);
            if (it != wantUMap.end())
            {
                it->second++;
            }
        }
    }

    return currentPassCount;
}

int main()
{
    vector<string> want;
    vector<int> number;
    vector<string> discount;
    want = { "banana", "apple", "rice", "pork", "pot" };
    number = { 3, 2, 2, 2, 1 };
    discount = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };

    //want = { "apple" };
    //number = { 10 };
    //discount = { "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana" };

    cout << solution(want, number, discount);

}

// 슬라이딩 윈도우를 할 때 위에처럼 해도 되지만
// 좀더 안정성을 위해서 공간복잡도를 포기하고 
// umap과 같은 자료구조를 매번 새로 할당하는 것이 추천됨
