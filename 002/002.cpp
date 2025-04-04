#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>& solution(vector<int>& input)
{
    input.erase(unique(input.begin(), input.end()), input.end());// O(N)

    return input;
}

int main()
{
    vector<int> lst = { 5, 10, 9, 12, 2, 9 };
    vector<int> result;

    sort(lst.begin(), lst.end(), [](int a, int b)->bool { return a > b; });// O(NlogN)
    result = solution(lst);

    for (auto i : result)
        cout << i << " ";
}

// erase와 unique
// 사용자 정의 bool
