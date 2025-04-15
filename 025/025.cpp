// 025.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;

    unordered_map<string, vector<int>> umap;
    
    for (size_t i = 0; i < genres.size(); i++)
    {
        if (umap.find(genres[i]) == umap.end())
        {
            umap[genres[i]].push_back(0); // 재생횟수
            umap[genres[i]].push_back(-1); // TOP1 index
            umap[genres[i]].push_back(-1); // TOP2 index
        }
    }

    for (size_t i = 0; i < genres.size(); i++)
    {
        umap[genres[i]][0] += plays[i]; // 재생횟수
        
        // 하나라도 비어있는 경우
        if (umap[genres[i]][1] == -1 && umap[genres[i]][2] == -1) // 두자리 다 비어있는 경우
        {
            umap[genres[i]][1] = i; // 1자리에 넣기
            continue;
        }
        if (umap[genres[i]][2] == -1) // 두번째 자리만 비어있는 경우
        {
            umap[genres[i]][2] = i; // 2자리에 넣기

            if (plays[umap[genres[i]][1]] < plays[umap[genres[i]][2]]) // 재생수 순 정렬
            {
                swap(umap[genres[i]][1], umap[genres[i]][2]);
            }
            else if (plays[umap[genres[i]][1]] == plays[umap[genres[i]][2]]) // 재생수 같으면
            {
                if (umap[genres[i]][1] < umap[genres[i]][2]) // 인덱스 순 정렬
                {
                    swap(umap[genres[i]][1], umap[genres[i]][2]);
                }
            }
            continue;
        }

        // 일반적인 경우
        if (plays[umap[genres[i]][2]] < plays[i]) // 2랑 비교
        {
            umap[genres[i]][2] = i; // 2자리에 넣기

            if (plays[umap[genres[i]][1]] < plays[umap[genres[i]][2]]) // 재생수 순 정렬
            {
                swap(umap[genres[i]][1], umap[genres[i]][2]);
            }
            else if (plays[umap[genres[i]][1]] == plays[umap[genres[i]][2]]) // 재생수 같으면
            {
                if (umap[genres[i]][1] < umap[genres[i]][2]) // 인덱스 순 정렬
                {
                    swap(umap[genres[i]][1], umap[genres[i]][2]);
                }
            }
        }

       
    }

    priority_queue<pair<int, string>> genreRank;
    for (auto it = umap.begin(); it != umap.end(); it++)
    {
        genreRank.push(make_pair(it->second.front(), it->first));
    }

    while (genreRank.empty() == false)
    {
        string currentGenre = genreRank.top().second;
        genreRank.pop();

        answer.push_back(umap[currentGenre][1]);
        if (umap[currentGenre][2] != -1) // 비어있을 수 있음
        {
            answer.push_back(umap[currentGenre][2]);
        }
    }


    return answer;
}

int main()
{
    vector<string> genres;
    vector<int> plays;

    genres = { "classic", "pop", "classic", "classic", "pop" };
    plays = { 500, 600, 150, 800, 2500 };

    vector<int> result = solution(genres, plays);
    for (auto i : result)
        cout << i << " ";

}

// 더 깔끔한 풀이들이 있으니 참고 요망

// 정렬에 사용할 사용자 bool타입형을 수동으로 만드는 부분도 적응할 필요가 있음
