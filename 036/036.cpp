// 036.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


unordered_map<char, vector<char>> umap;
unordered_map<char, bool> visited;

void DFS(char cur, vector<char>& answer)
{
    visited[cur] = true;
    answer.push_back(cur);

    for (size_t i = 0; i < umap[cur].size(); i++)
    {
        if (visited[umap[cur][i]] == true)
            continue;

        DFS(umap[cur][i], answer);
    }

}

vector<char> solution(vector<pair<char, char>> graph, char start)
{
    for (size_t i = 0; i < graph.size(); i++)
    {
        umap[graph[i].first].push_back(graph[i].second);
        visited[graph[i].first] = false;
        visited[graph[i].second] = false;

    }

    vector<char> answer;
    DFS(start, answer);

    return answer;
}

int main()
{
    vector<pair<char, char>> graph;
    char start;

    //graph = { {'A','B'},{'B','C'},{'C','D'},{'D','E'} };
    //start = 'A';

    graph = { {'A','B'},{'A','C'},{'B','D'},{'B','E'},{'C','F'},{'E','F'} };
    start = 'A';

    vector<char> result = solution(graph, start);
    for (auto c : result)
        cout << c << " ";

}

