// 031.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int centerMoney = 0;
int totalMoney = 0;

int Share(int money, int index, vector<int>& answer, vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount, unordered_map<string, int> umap)
{
    if (referral[index] == "-")
    {
        centerMoney += (int)(money * 0.1f);
        totalMoney += centerMoney;
        return totalMoney;
    }
    if (money < 10) //if (money * 0.9f < 1.0f)
    {
        return 0;
    }

    // 돈 나누기
    int nextMoney = (int)(money * 0.1f);
    string next = referral[index];
    int nextIndex = umap[next];

    int returnMoney = Share(nextMoney, nextIndex, answer, enroll, referral, seller, amount, umap);

    // 돈 작성
    answer[nextIndex] += nextMoney - returnMoney;
    totalMoney += nextMoney - returnMoney;

    return totalMoney;

}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) 
{
    vector<int> answer;
    answer.resize(enroll.size());

    unordered_map<string, int> umap;

    for (size_t i = 0; i < enroll.size(); i++)
    {
        umap.insert(make_pair(enroll[i], i));
    }

    for (size_t i = 0; i < seller.size(); i++)
    {
        int curMemberIndex = umap[seller[i]];
        if ((amount[i] * 100.f) * 0.9f < 1.0f)
        {
            answer[curMemberIndex] += (amount[i] * 100.0f);
        }
        else
        {
            answer[curMemberIndex] += (amount[i] * 100.0f) * 0.9f;
            Share(amount[i] * 100.f, curMemberIndex, answer, enroll, referral, seller, amount, umap);
            centerMoney = 0;
            totalMoney = 0;
        }

    }

    return answer;
}

int main()
{
    vector<string> enroll;
    vector<string> referral;
    vector<string> seller;
    vector<int> amount;

    enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
    referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
    seller = { "young", "john", "tod", "emily", "mary" };
    amount = { 12, 4, 2, 5, 10 };

    enroll = { "john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young" };
    referral = { "-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward" };
    seller = { "sam", "emily", "jaimie", "edward" };
    amount = { 2, 3, 5, 4 };

    vector<int> result = solution(enroll, referral, seller, amount);
    for (auto i : result)
        cout << i << " ";
}

