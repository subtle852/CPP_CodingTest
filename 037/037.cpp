// 037.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, vector<int>> connectedMap;
unordered_set<int> visitedSet;
queue<int> q;

vector<int> solution(vector<pair<int, int>> graph, int start)
{
    vector<int> answer;

    for (size_t i = 0; i < graph.size(); i++)
    {
        connectedMap[graph[i].first].push_back(graph[i].second);
    }

    q.push(start);
    visitedSet.insert(start);
    while (q.empty() == false)
    {
        int cur = q.front();
        q.pop();
        answer.push_back(cur);

        for (size_t i = 0; i < connectedMap[cur].size(); i++)
        {
            if (visitedSet.find(connectedMap[cur][i]) != visitedSet.end())
                continue;

            q.push(connectedMap[cur][i]);
            visitedSet.insert(connectedMap[cur][i]);
        }
    }

    return answer;
}



int main()
{
    vector<pair<int, int>> graph;
    int start;

    graph = { {1,2}, {1,3}, {2,4}, {2,5}, {3,6}, {3,7}, {4,8}, {5,8}, {6,9}, {7,9}};
    start = 1;

    //graph = { {0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,0} };
    //start = 1;

    vector<int> result = solution(graph, start);
    for (auto i : result)
        cout << i << " ";

}
