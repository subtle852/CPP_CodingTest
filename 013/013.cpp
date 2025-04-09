// 013.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>>& board, vector<int>& moves)
{
	for_each(moves.begin(), moves.end(), [](int& value) { --value; });

	stack<int> basket;

	int count = 0;

	for (size_t i = 0; i < moves.size(); i++)
	{
		for (size_t j = 0; j < board.size(); j++)
		{
			int temp = board[j][moves[i]];
			if (temp == 0)
			{
				continue;
			}
			else
			{
				if (basket.empty() == false && basket.top() == temp)
				{
					basket.pop();
					count += 2;
					break;
				}
				else
				{
					basket.push(temp);
					board[j][moves[i]] = 0;
					break;
				}
			}
		}
	}

	return count;
}

int main()
{
	vector<vector<int>> board;
	vector<int> moves;

	board = {
		{ 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 3 },
		{ 0, 2, 5, 0, 1 },
		{ 4, 2, 4, 4, 2 },
		{ 3, 5, 1, 3, 1 }
	};

	moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

	int result = solution(board, moves);
	cout << result;


}
