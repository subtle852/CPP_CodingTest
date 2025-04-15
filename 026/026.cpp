// 026.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) 
{
    vector<int> answer;

    unordered_map<string, vector<string>> reportedIDs;
    unordered_map<string, int> reportedCount;

    unordered_map<string, vector<string>> suspendedIDs;

    for (size_t i = 0; i < report.size(); i++) // reportedCount 추출 (reportedIDs를 통해 중복은 안되도록)
    {
        stringstream s(report[i]);
        string userID; 
        string reportedUserID;
        s >> userID;
        s >> reportedUserID;

        if (find(reportedIDs[userID].begin(), reportedIDs[userID].end(), reportedUserID) == reportedIDs[userID].end())
        {
            reportedIDs[userID].push_back(reportedUserID);
            reportedCount[reportedUserID]++;
        }
    }

    for (size_t i = 0; i < report.size(); i++) // suspendedIDs 추출
    {
        stringstream s(report[i]);
        string userID;
        string suspendedUserID;
        s >> userID;
        s >> suspendedUserID;
        
        if (find(suspendedIDs[userID].begin(), suspendedIDs[userID].end(), suspendedUserID) == suspendedIDs[userID].end())
        {
            if (reportedCount[suspendedUserID] >= k) // 벤 당한 애들만 추가
            {
                suspendedIDs[userID].push_back(suspendedUserID);
            }
        }
    }

    for (size_t i = 0; i < id_list.size(); i++)
    {
        if (suspendedIDs.find(id_list[i]) == suspendedIDs.end()) // 없을 수 도 있음
        {
            answer.push_back(0);
            continue;
        }
        answer.push_back(suspendedIDs[id_list[i]].size());
    }
    int a = 0;

    return answer;
}

int main()
{
    vector<string> id_list;
    vector<string> report;
    int k;

    id_list = { "muzi", "frodo", "apeach", "neo" };
    report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    k = 2;

    //id_list = { "con", "ryan" };
    //report = { "ryan con", "ryan con", "ryan con", "ryan con" };
    //k = 3;

    vector<int> result = solution(id_list, report, k);



}
