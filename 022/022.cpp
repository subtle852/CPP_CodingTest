// 022.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phoneBook)
{
    unordered_map<string, int> umap;
    for (size_t i = 0; i < phoneBook.size(); i++)
    {
        string key = "";
        for (size_t j = 0; j < phoneBook[i].size(); j++)
        {
            key += phoneBook[i][j];
            umap[key]++;
        }
    }
    
    for (size_t i = 0; i < phoneBook.size(); i++)
    {
        if (umap[phoneBook[i]] >= 2)
            return false;
    }

    return true;
    
}

int main()
{
    vector<string> phoneBook;
    //phoneBook = { "119", "97674223", "1195524421" }; // f
    //phoneBook = { "123","456","789" }; // t
    //phoneBook = { "12","123","1235","567","88" }; // f
    phoneBook = {  "911", "97625999", "91125426" }; // f

    cout << solution(phoneBook);

}

// 위의 방식을 반대로 구현하는 방식이 훨씬 공간복잡도 적게 차지
// 정렬 방식은 NlogN으로 가장 시간복잡도가 낮음 
// (물론 전화번호의 길이는 최대 20이기에 
// log 20 (== 19.6) > 20 으로 별 차이 없긴 함)
