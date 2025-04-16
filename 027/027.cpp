//// 027.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
////
//
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//map<string, int> combi;
//void combination(string src, string dst, int depth)
//{
//	if (dst.size() == depth)
//		combi[dst]++;
//
//	else
//	{
//		for (size_t i = 0; i < src.size(); i++)
//		{
//			combination(src.substr(i + 1), dst + src[i], depth);
//		}
//	}
//}
//
//vector<string> solution(vector<string> orders, vector<int> course) 
//{
//	vector<string> answer;
//
//	for (auto order : orders)
//		sort(order.begin(), order.end());
//
//	for (auto len : course)
//	{
//		for (auto order : orders)
//			combination(order, "", len);
//
//		int maxOrder = 0;
//		for (auto it : combi)
//			maxOrder = max(maxOrder, it.second);
//
//		for (auto it : combi)
//			if (maxOrder >= 2 && it.second == maxOrder)
//				answer.push_back(it.first);
//
//		combi.clear();
//	}
//
//	sort(answer.begin(), answer.end());
//
//	return answer;
//}
//
//int main()
//{
//	vector<string> orders;
//	vector<int> course;
//	vector<string> result;
//
//	orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
//	course = { 2,3,4 };
//
//	orders = { "ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD" };
//	course = { 2,3,5 };
//	
//	orders = { "XYZ", "XWY", "WXA" };
//	course = { 2,3,4 };
//
//	result = solution(orders, course);
//	for (auto s : result)
//		cout << s << " ";
//
//}
//
//// 조합을 만들어내는 코드가 핵심
//
//// 조금더 이해가 쉬우면서 직관적인 풀이는 027-1
