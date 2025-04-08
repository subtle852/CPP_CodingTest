// 012.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int>solution(const vector<int>& prices)
{
	vector<int> result;
	result.resize(prices.size());

	stack<int> IndexStack;
	for (size_t i = 0; i < prices.size(); i++)
	{
		if (i == 0)
		{
			IndexStack.push(i);
			continue;
		}

		while (prices[IndexStack.top()] > prices[i]) // 하락 발생
		{
			result[IndexStack.top()] = i - IndexStack.top();
			IndexStack.pop();
		}
		IndexStack.push(i);
	}

	while (IndexStack.empty() == false)
	{
		result[IndexStack.top()] = (prices.size() - 1) - IndexStack.top();
		IndexStack.pop();
	}

	return result;
}

int main()
{
    vector<int> prices = { 1, 2, 3, 2, 3 };
    //vector<int> prices = { 1, 3, 5, 4, 2, 5, 1 };
    vector<int> result = solution(prices);
	for (size_t i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}
