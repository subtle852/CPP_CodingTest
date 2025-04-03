#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lst;
vector<int> result;

vector<int> solution()
{
    lst.erase(unique(lst.begin(), lst.end()), lst.end());// O(N)
}

int main()
{
    lst = { 5, 10, 9, 12, 2, 9 };

    sort(lst.begin(), lst.end(), [](int a, int b)->bool { return a > b; });// O(NlogN)
    result = solution();

    for (auto i : result)
        cout << i << " ";
}

// erase와 unique
// 사용자 정의 bool
