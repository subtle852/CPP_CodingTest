// 021.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    unordered_set<string> uset;
    uset.insert(words[0]);

    int errorTotalIndex = -1;
    for (size_t i = 1; i < words.size(); i++)
    {
        if (words[i - 1].back() != *(words[i].begin()))
        {
            errorTotalIndex = i;
            break;
        }

        if (uset.find(words[i]) != uset.end())
        {
            errorTotalIndex = i;
            break;
        }

        uset.insert(words[i]);
    }

    vector<int> result;
    if (errorTotalIndex == -1) // 발생하지 않은 경우
    {
        result.push_back(0);
        result.push_back(0);

        return result;
    }

    int num = errorTotalIndex % n + 1;
    int order = errorTotalIndex / n + 1;
    result.push_back(num);
    result.push_back(order);

    return result;
}

int main()
{
    int n;
    vector<string> words;

    //n = 3;
    //words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
    
    n = 5;
    words = { "hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive" };
    
    //n = 2;
    //words = { "hello", "one", "even", "never", "now", "world", "draw" };

    vector<int> result = solution(n, words);
    
    for (auto i : result)
        cout << i << " ";

}

// insert bool 반환
