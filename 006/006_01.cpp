#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;
vector<int> stages;
vector<int> result;

vector<int>& solution(vector<int>& InResult)
{
	map<float, vector<int>, greater<float>> tempMap;

	vector<int> ups(N+2, 0);
	vector<int> downs(N+2, 0);
	vector<int> failures(N+2, 0);

	// 006 풀이와는 다르게 Stage 하나씩 채워가는 것이 아닌
	// stages를 돌면서, 배열에 결과를 채워가는 방식
	for (size_t i = 0; i < stages.size(); i++)
	{
		for (size_t j = 1; j <= stages[i]; j++)
		{
			if (j == stages[i])
			{
				ups[j]++;
			}
			else
			{
				downs[j]++;
			}
		}
	}

	for (size_t i = 1; i <= N; i++)
	{
		float faliurePercent;
		if (downs[i] == 0)
		{
			faliurePercent = 0.f;
		}
		else
		{
			faliurePercent = (float)ups[i] / (float)downs[i] * (float)100;
		}

		tempMap[faliurePercent].push_back(i);
	}

	for (auto it = tempMap.begin(); it != tempMap.end(); it++)
	{
		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
		{
			InResult.push_back(*it2);
		}
	}

	return InResult;
}

int main()
{
	N = 5;
	stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

	//N = 4;
	//stages = { 4, 4, 4, 4, 4 };

	result = solution(result);

	for (auto i : result)
	{
		cout << i << " ";
	}


}

