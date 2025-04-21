// 035.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple>

using namespace std;

int solution(int n, vector<vector<int>> costs)
{
    unordered_map<int, vector<pair<int, int>>> umap; // 0 - 1, 1 / 0 - 2,2

    for (size_t i = 0; i < costs.size(); i++)
    {
        { // 0 - 1,1
            int key = *costs[i].begin();
            pair<int, int> value = { *(++costs[i].begin()), *(++++costs[i].begin()) };
            umap[key].push_back(value);
        }
        { // 1 - 0,1
            int key = *(++costs[i].begin());
            pair<int, int> value = { *costs[i].begin(), *(++++costs[i].begin()) };
            umap[key].push_back(value);
        }
    }

    vector<int> parent(n);
    for (int i = 0; i < n; i++) // 올바른 초기화
    {
        parent[i] = i;
    }

    auto judge = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b)
        {
            return get<2>(a) > get<2>(b);
        };

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(judge)> pq(judge);

    bool alredyDone[100][100] = { false, };

    int minCost = 0;

    int i = 0;
    while(true)
    {
        // 하나 선택하고
        if (umap.find(i) == umap.end())
            continue;

        for (size_t j = 0; j < umap[i].size(); j++) // 선택한 것을 기준으로 연결된 애들 확인
        {
            pair<int, int> value = umap[i][j];
            int src = i;
            int dst = value.first;
            int cost = value.second;
            
            if (alredyDone[src][dst] == true) // 중복 거르기
                continue;

            pq.push(make_tuple(src, dst, cost));
        }

		tuple<int, int, int> select = pq.top(); // pq 하나 뽑아서 확인
		pq.pop();

		int src = get<0>(select);
		int dst = get<1>(select);
		int cost = get<2>(select);

        // 결과 삽입
		parent[dst] = src;
        alredyDone[src][dst] = true;
        alredyDone[dst][src] = true;
        minCost += cost;

		// 연결 완료 확인
		bool IsAllConnected = true;
		for (size_t i = 0; i < parent.size(); i++)
		{
            int tempForFindRoot = parent[i];
            while (parent[tempForFindRoot] != tempForFindRoot)
            {
                tempForFindRoot = parent[tempForFindRoot]; // 최상위 부모 찾기 및 변경
            }
            parent[i] = tempForFindRoot;

            if (parent[i] != 0) // 모두 동일한 (0 '시작점') 부모 == 연결 완료
            {
                IsAllConnected = false;
                break;
            }
		}

        if (IsAllConnected == true)
            break;

        i = dst;
	}


    return minCost;
}

int main()
{
    int n;
    vector<vector<int>> costs;

    n = 4;
    costs = { {0,1,1}, {0,2,2},{1,2,5},{1,3,1},{2,3,8}};
    cout << solution(n, costs);

}
