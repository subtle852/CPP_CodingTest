// 038.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int MAX_NODES = 100;
int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

vector<int> solution(int start, int numNodes, vector<tuple<int,int,int>> edges)
{
	for (size_t i = 0; i < MAX_NODES; i++)
	{
		fill_n(graph[i], MAX_NODES, INF);
		visited[i] = false;
	}

	for (const auto& edge : edges)
	{
		int from = get<0>(edge);
		int to = get<1>(edge);
		int weight = get<2>(edge);
		graph[from][to] = weight;
	}

	vector<int> distances(numNodes, INF);
	distances[start] = 0;

	for (int i = 0; i < numNodes - 1; ++i) 
	{
		int minDistance = INF;
		int closestNode = -1;

		for (int j = 0; j < numNodes; ++j) 
		{
			if (!visited[j] && distances[j] < minDistance) 
			{
				minDistance = distances[j];
				closestNode = j;
			}
		}

		visited[closestNode] = true;

		for (int j = 0; j < numNodes; ++j) 
		{
			int newDistance = distances[closestNode] + graph[closestNode][j];
			if (!visited[j] && graph[closestNode][j] != INF && newDistance < distances[j]) 
			{
				distances[j] = newDistance;
			}
		}
	}

	return distances;
}

int main()
{
	int start;
	int numNodes;
	vector<tuple<int, int, int>> edges;

	start = 0;
	numNodes = 3;
	edges = { {0,1,9}, {0,2,3}, {1,0,5}, {2,1,1} };

	start = 0;
	numNodes = 4;
	edges = { {0,1,1}, {1,2,5}, {2,3,1} };

	vector<int> result = solution(start, numNodes, edges);
	for (auto i : result)
		cout << i << " ";
}

