// 010.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int solution(const string& s)
{
	int count = 0;

	stack<char> tempStack;

	for (size_t i = 0; i < s.size(); i++)
	{
		int whileCount = s.size();
		for (size_t j = i; whileCount != 0; )
		{
			if (s[j] == '(' || s[j] == '[' || s[j] == '{')
			{
				tempStack.push(s[j]);
			}
			else
			{
				if (tempStack.empty() == false)
				{
					if (tempStack.top() == '(' && s[j] == ')')
					{
						tempStack.pop();
					}
					else if (tempStack.top() == '[' && s[j] == ']')
					{
						tempStack.pop();
					}
					else if (tempStack.top() == '{' && s[j] == '}')
					{
						tempStack.pop();
					}
					else
					{
						tempStack.push('0'); // Stack 쓰레기값 강제 push
						break; // 앞괄호가 와있는데 매치가 안되는 뒷괄호가 들어온 경우니 비정상
					}
				}
				else
				{
					tempStack.push('0'); // Stack 쓰레기값 강제 push
					break; // 비어있는데 뒷괄호가 오면 비정상
				}
			}

			whileCount--;

			j++;
			j %= s.size();
		}

		if (tempStack.empty() == true)
		{
			count++;
		}
		while(tempStack.empty() == false)
		{
			tempStack.pop();
		}
	}

	return count;
}

int main()
{
	string s = "[](){}";
	//string s = "}]()[{";
	//string s = "[)(]";
	//string s = "}}}";
	int result = solution(s);
	cout << result;

}
