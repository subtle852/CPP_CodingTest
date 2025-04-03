#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	// N!		10
	// 2^N		20
	// N^3		100
	// N^2		1000
	// NlogN	100만
	// N		1000만
	// logN		10억


	vector<int> v;
	//for (size_t i = 0; i < 5; i++)
	//{
	//	int input;
	//	cin >> input;
	//	v.push_back(input);
	//}

	v = { 5, 3, 10, 9, 2 };

	// bubble sort O(N^2)
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		for (size_t j = 0; j < v.size() - 1 - i; j++)
		{
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}

	// sort O(logN)
	sort(v.begin(), v.end());

	//sort(v.begin(), v.end(), [](int a, int b) { return a > b;});

	for (auto i: v)
	{
		cout << i << " ";
	}
}

// 시간복잡도
// sort
// swap
// bubble sort 구현
