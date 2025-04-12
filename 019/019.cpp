// 019.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

long long MyHash(const string& s)
{
    long long p = 31.0;
    long long m = 1'000'000'007;

    int value = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        value = (value * p + s[i]) % m;
    }

    return value;
}

vector<bool> solution(vector<string> string_list, vector<string> query_list)
{
    vector<bool> result;
    unordered_set<long long> uset;

    for (size_t i = 0; i < string_list.size(); i++)
    {
        long long hashValue = MyHash(string_list[i]);
        uset.insert(hashValue);
    }

    for (size_t i = 0; i < query_list.size(); i++)
    {
        if (uset.find(MyHash(query_list[i])) != uset.end())
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }
    }

    return result;
}

int main()
{
    vector<string> string_list = { "apple", "banana", "cherry" };
    vector<string> query_list = { "banana", "kiwi", "melon", "apple" };

    vector<bool> result;

    result = solution(string_list, query_list);
    for (auto b : result)
        cout << b << " ";

}
