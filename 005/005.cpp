#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    vector<vector<int>> arr1 =
    {
        { 3, 1},
        { 2, 4},
    };
    vector<vector<int>> arr2 =
    {
        { 1, 7, 3},
        { 5, 3, 2},
    };

    vector<vector<int>> result;

    int arr1size = arr1[0].size();// 2
    int arr2size = arr2[0].size();// 3

    //result.resize(arr1size, vector<int>(arr2size));
    result.assign(arr1size, vector<int>(arr2size, 0));

    //result.resize(arr1size);
    //for (size_t i = 0; i < arr1size; i++)
    //{
    //    result[i].resize(arr2size);
    //}

    int Value = 0;

    for (size_t i = 0; i < arr1size; i++)
    {
        for (size_t j = 0; j < arr2size; j++)
        {
            Value = 0;
            for (size_t k = 0; k < arr1size; k++)
            {
                Value += arr1[i][k] * arr2[k][j];

                result[i][j] = Value;
            }
        }
    }

    for (size_t i = 0; i < arr1size; i++)
    {
        for (size_t j = 0; j < arr2size; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

}

// 이차원 vector resize, assign

