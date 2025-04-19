// 034.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> uset;
    for (auto i : nums)
        uset.insert(i);

    int typeCount = uset.size();
    int takeCount = nums.size() / 2;

    if (typeCount < takeCount)
        return typeCount;

    return takeCount;

}

int main()
{
    vector<int> nums, nums1, nums2;

    nums = { 3, 1, 2, 3 };
    nums1 = { 3, 3, 3, 2, 2, 4};
    nums2 = { 3, 3, 3, 2, 2, 2};

    cout << solution(nums);
    cout << solution(nums1);
    cout << solution(nums2);


}
