// 024.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<string> solution(vector<string> record) 
{
    vector<string> answer;

    unordered_map<string, string> hash;
    

    for (size_t i = 0; i < record.size(); i++) // 가장 최근 uid - 닉네임 추출
    {
        int firstSpace = 0;
        int secondSpace = 0;
        for (size_t j = 0; j < record[i].size(); j++)
        {
            if (record[i][j] == ' ')
            {
                if (firstSpace == 0)
                {
                    firstSpace = j + 4;
                }
                else
                {
                    secondSpace = j;
                }
            }
        }
        string uid = record[i].substr(firstSpace, secondSpace - firstSpace);


        if (record[i].front()  == 'E' || record[i].front() == 'C') // 가장 최근 Enter나 Change
        {
            hash[uid] = record[i].substr(secondSpace + 1, 10);
        }
    }

    for (size_t i = 0; i < record.size(); i++) // record -> result 변경
    {
        if (record[i].front() == 'C') // Change는 표시하지 않음
            continue;

        string s = "";

        int firstSpace = 0;
        int secondSpace = 0;
        for (size_t j = 0; j < record[i].size(); j++) // uid 추출
        {
            if (record[i][j] == ' ')
            {
                if (firstSpace == 0)
                {
                    firstSpace = j + 4;
                }
                else
                {
                    secondSpace = j;
                }
            }
        }
        string uid = record[i].substr(firstSpace, secondSpace - firstSpace);
        auto nickname = hash.find(uid);
        if (nickname != hash.end())
        {
            s += nickname->second;
        }
        s += "님이 ";

        if (record[i].front() == 'E')
        {
            s += "들어왔습니다.";
        }
        if (record[i].front() == 'L')
        {
            s += "나갔습니다.";
        }

        answer.push_back(s);
    }

    return answer;
}

int main()
{
    vector<string> record;
    record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

    vector<string> result = solution(record);
    for (auto s : result)
        cout << s << endl;

}

// break continue 실수 유의

// 024-1에서 사용하는 공백을 기준으로 알아서 파싱하는 sstream 헤더를 이용한 방식도 중요
