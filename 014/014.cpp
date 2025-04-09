//// 014.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
////
//
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <string>
//
//using namespace std;
//
//string result;
//
//const string& solution(int n, int k, const vector<string>& cmd)
//{
//    stack<int> basic;
//    for (size_t i = 0; i < n; i++) // basic 초기화
//    {
//        basic.push(i);
//    }
//
//    stack<int> restore;
//    for (size_t i = 0; i < cmd.size(); i++)
//    {
//        if (cmd[i] == "C")
//        {
//            if (k == basic.size() - 1) // index k가 끝인 경우
//            {
//                basic.pop();
//                restore.push(k);
//                k--;
//            }
//            else
//            {
//                basic.pop();
//                restore.push(k);
//            }
//        }
//        else if(cmd[i] == "Z")
//        {
//            basic.push(basic.size());
//
//            int insertPos = restore.top();
//            if (insertPos == basic.size() - 1) // 맨끝에 들어가는 경우
//            {
//                k++;
//            }
//            else if (insertPos <= k) // k 보다 이전에 들어가는 경우
//            {
//                k++;
//            }
//
//            restore.pop();
//        }
//        else
//        {
//            char first = cmd[i][0];
//            string secondString = cmd[i].substr(2);
//            int second = stoi(secondString);
//
//            if (first == 'D')
//            {
//
//                k += second;
//            }
//            else // U
//            {
//                k -= second;
//            }
//        }
//    }
//
//    for (size_t i = 0; i < n; i++)
//    {
//        result += "O";
//    }
//
//    while(restore.empty() == false) // result 반환 문자열 작성
//    {
//        result[restore.top()] = 'X';
//        restore.pop();
//    }
//
//    return result;
//}
//
//int main()
//{
//    int n, k;
//    vector<string> cmd;
//
//    n = 6;
//    k = 3;
//    //cmd = { "D 2", "C", "U 3", "C", "D 4" , "C", "U 2", "Z", "Z" };
//    //cmd = { "D 2", "C", "U 3", "C", "D 4" , "C", "U 2", "Z", "Z", "U 1", "C" };
//    cmd = { "U 2", "C", "D 3", "C", "Z", "U 1", "C" };
//
//    string answer = solution(n, k, cmd);
//    cout << answer;
//
//}
//
//// #include <string> 활용
//// substr(시작인덱스) substr(시작인덱스, 끝인덱스)
//// stoi 
//// 
//// 이중반복문이라고 하더라도 무조건 O(N^2)은 아님
//// 최대 횟수가 딱 정해져있는 L이라면 
//// O(N * L)로 예를들어 O(N * 10) == O(N)
