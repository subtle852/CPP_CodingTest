#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(const vector<int>& input)
{
	set<int> tmp;

	for (size_t i = 0; i < input.size() - 1; i++)
	{
		for (size_t j = 0; j < input.size() - 1; j++)
		{
			if (i <= j)
				break;

			int value = input[i] + input[j];
			tmp.insert(value);
		}
	}

	vector<int> tmp2;

	// 초기화 버전 (형변환)
	vector<int> tmp3(tmp.begin(), tmp.end());
	// 순회 버전
	//for_each(tmp.begin(), tmp.end(), [&](int value) { tmp2.push_back(value);});

	return tmp2;
}

int main()
{
	vector<int> v = { 2, 1, 3, 4, 1 };
	vector<int> result;
	result = solution(v);

	for (auto i : result)
	{
		cout << i << " ";
	}

}

// 중복을 허용하지 않는 경우는 set, map, unordered_set, unordered_map 사용 가능
// 형변환 ex. set -> vector
