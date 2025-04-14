#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) 
{
    unordered_map<string, string> uidToName;
    vector<pair<string, string>> actions; // {uid, action}

    for (const auto& r : record) 
    {
        istringstream iss(r);
        string cmd, uid, name;
        iss >> cmd >> uid;
        if (cmd == "Enter" || cmd == "Change") 
        {
            iss >> name;
            uidToName[uid] = name;
        }
        if (cmd == "Enter" || cmd == "Leave") 
        {
            actions.push_back({ uid, cmd });
        }
    }

    vector<string> answer;
    for (const auto& action : actions) 
    {
        string uid = action.first;
        string cmd = action.second;

        string msg = uidToName[uid] + "님이 ";
        msg += (cmd == "Enter") ? "들어왔습니다." : "나갔습니다.";
        answer.push_back(msg);
    }

    return answer;
}

int main() {
    vector<string> record = 
    {
        "Enter uid1234 Muzi",
        "Enter uid4567 Prodo",
        "Leave uid1234",
        "Enter uid1234 Prodo",
        "Change uid4567 Ryan"
    };

    vector<string> result = solution(record);
    for (const auto& s : result) 
    {
        cout << s << endl;
    }
}
