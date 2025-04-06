//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <map>
//#include <algorithm>
//using namespace std;
//
//int solution(const string& input)
//{
//    vector<pair<int,int>> bfPos;
//    //vector<int> dir;
//
//    map<tuple<int, int, char>, bool> visited;
//
//    bfPos.push_back(make_pair(0, 0));
//    int count = 0;
//
//    for (auto i = 0; i < input.size(); i++)
//    {
//        if (i == 0)
//        {
//            visited.insert(make_pair(make_tuple(bfPos[i].first, bfPos[i].second, input[i]), true));
//            count++;
//            continue;
//        }
//
//        pair<int, int> tempPos;
//
//        switch (input[i - 1])
//        {
//        case 'U':
//            tempPos.first = bfPos[i - 1].first;
//            tempPos.second = bfPos[i - 1].second + 1;
//            break;
//
//        case 'D':
//            tempPos.first = bfPos[i - 1].first;
//            tempPos.second = bfPos[i - 1].second - 1;
//            break;
//
//        case 'R':
//            tempPos.first = bfPos[i - 1].first - 1;
//            tempPos.second = bfPos[i - 1].second;
//            break;
//
//        case 'L':
//            tempPos.first = bfPos[i - 1].first + 1;
//            tempPos.second = bfPos[i - 1].second;;
//
//            break;
//        }
//
//        if (abs(tempPos.first) > 5 || abs(tempPos.second) > 5) // 범위 초과
//        {
//            bfPos.push_back(bfPos.back());
//            continue;
//        }
//        else
//        {
//            bfPos.push_back(tempPos);
//        }
//
//        if (visited[make_tuple(bfPos[i].first, bfPos[i].second, input[i])] == true) // 방문한 적 있는 경우
//        {
//            continue;
//        }
//
//        //visited.insert(make_pair(make_tuple(bfPos[i].first, bfPos[i].second, input[i]), true));
//        visited[make_tuple(bfPos[i].first, bfPos[i].second, input[i])] = true;
//        count++;
//
//    }
//
//    return count;
//
//}
//
//int main()
//{
//    //string dirs = "ULURRDLLU";
//    //string dirs = "LULLLLLLU";
//    string dirs = "LRLRLR";
//
//    int result = solution(dirs);
//    cout << result;
//
//}
//
//// 시작지점과 방향만을 저장하다보니
//// A -> B, B -> A는 다른 길이라고 생각을 하는 문제가 발생
//
//// unordered_map 내부에서는 pair나 tuple을 그냥 사용할 수 없기에 
//// 직접 사용자 정의 해시함수 작성 필요
//// 그냥 map을 사용하는 방식을 추천 