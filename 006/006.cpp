//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//int N;
//vector<int> stages;
//vector<int> result;
//
//vector<int>& solution(vector<int>& InResult)
//{
//	map<float, vector<int>, greater<float>> tempMap;
//
//	for (size_t i = 1; i <= N; i++)
//	{
//		int up = 0;
//		int down = 0;
//
//		for (size_t j = 0; j < stages.size(); j++)
//		{
//			if (stages[j] >= i)
//			{
//				down++;
//			}
//			if (stages[j] == i)
//			{
//				up++;
//			}
//
//			if (j == stages.size() - 1)
//			{
//				float faliurePercent;
//				if (down == 0)
//				{
//					faliurePercent = 0.f;
//				}
//				else
//				{
//					faliurePercent = (float)up / (float)down * (float)100;
//				}
//
//				tempMap[faliurePercent].push_back(i);
//			}
//		}
//	}
//
//	for (auto it = tempMap.begin(); it != tempMap.end(); it++)
//	{
//		for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
//		{
//			InResult.push_back(*it2);
//		}
//	}
//
//	return InResult;
//}
//
//int main()
//{
//    N = 5;
//	stages = { 2, 1, 2, 6, 2, 4, 3, 3 };
//
//	//N = 4;
//	//stages = { 4, 4, 4, 4, 4 };
//	
//	result = solution(result);
//
//	for (auto i : result)
//	{
//		cout << i << " ";
//	}
//
//
//}
