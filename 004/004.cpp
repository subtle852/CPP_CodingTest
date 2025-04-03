#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> answer = { 1, 2, 3, 4, 5, 1, 3, 4, 2, 1, 5, 2, 3, 2, 3, 1, 1, 5 };

int main()
{
    vector<int> A;
    vector<int> B;
    vector<int> C;

    vector<int> Scores;

    for (size_t i = 0; i < answer.size(); i++)
    {
        static int markA = 1;
        A.push_back(markA);

        // check
        if (answer[i] == markA)
            Scores[0]++;

        markA++;
        if (markA >= 6)
            markA = 1;
    }

    for (auto i : A)
    {
        cout << i << " ";
    }

    cout << endl;

    for (size_t i = 0; i < answer.size(); i++)
    {
        static int markB = 1;

        if (i % 2 == 0)
        {
            B.push_back(2);

            // check
            if (answer[i] == 2)
                Scores[1]++;
        }
        else
        {
            B.push_back(markB);

            // check
            if (answer[i] == markB)
                Scores[1]++;

            markB++;
            if (markB == 2)
                markB++;
            if (markB >= 6)
                markB = 1;
        }
    }

    for (auto i : B)
        cout << i << " ";

    cout << endl;

    vector<int> tmpForC = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    for (size_t i = 0; i < answer.size(); i++)
    {
        int markC = i % tmpForC.size();

        C.push_back(tmpForC[markC]);

        // check
        if (answer[i] == tmpForC[markC])
            Scores[2]++;
    }

    for (auto i : C)
        cout << i << " ";

    cout << endl;

    cout << Scores[0] << " " << Scores[1] << " " << Scores[2];

    int winnerScore = *max_element(Scores.begin(), Scores.end());

}

// 모듈러 연산 활용
// max_element
