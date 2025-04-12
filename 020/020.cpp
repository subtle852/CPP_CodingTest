// 020.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    unordered_map<string, int> umap;
    for (size_t i = 0; i < participant.size(); i++)
    {
        umap[participant[i]] += 1;
    }

    for (size_t i = 0; i < completion.size(); i++)
    {
        if (umap.find(completion[i]) != umap.end())
        {
            umap[completion[i]] -= 1;
        }

        if (umap[completion[i]] == 0)
        {
            umap.erase(completion[i]);
        }
    }
    
    return umap.begin()->first;
}

int main()
{
    vector<string> participant;
    vector<string> completion;

    //participant = { "leo", "kiki" , "eden" };
    //completion = { "eden", "kiki" };
    //participant = { "marina", "josipa" , "nikola", "vinko", "filipa" };
    //completion = { "josipa", "filipa", "marina", "nikola" };
    participant = { "mislav", "stanko" , "mislav", "ana" };
    completion = { "stanko", "ana", "mislav" };

    string result = solution(participant, completion);

    cout << result;

}
