// 032.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int number;
    int x, y;
    Node* left = nullptr;
    Node* right = nullptr;
};

class Tree
{
public:
    Tree(){}
    ~Tree()
    {

    }

    void Insert(const vector<int>& InVector)
    {
        Node* newnode = new Node;
        newnode->number = InVector.back();
        newnode->x = *(InVector.begin());
        newnode->y = *(++InVector.begin());

        if (root == nullptr)
        {
            root = newnode;
            compare = newnode;
            return;
        }

        if (newnode->x < compare->x)
        {
            if (compare->left == nullptr)
            {
                compare->left = newnode;
            }
            else
            {
                compare = compare->left;
                delete newnode; // 어짜피 재귀들어가면 새로 만드니
                Insert(InVector);
            }
        }
        else
        {
            if (compare->right == nullptr)
            {
                compare->right = newnode;
            }
            else
            {
                compare = compare->right;
                delete newnode; // 어짜피 재귀들어가면 새로 만드니
                Insert(InVector);
            }
        }

        compare = root; // 초기화
    }

    vector<int> PreOrder()
    {
        OutVector.clear();
        PreOrderRecur(root);
        return OutVector;
    }

    vector<int> PostOrder()
    {
        OutVector.clear();
        PostOrderRecur(root);
        return OutVector;
    }

private:
    void PreOrderRecur(Node* curNode)
    {
        if (curNode == nullptr)
            return;

        OutVector.push_back(curNode->number);
        PreOrderRecur(curNode->left);
        PreOrderRecur(curNode->right);

        return;
    }

    void PostOrderRecur(Node* curNode)
    {
        if (curNode == nullptr)
            return;

        PostOrderRecur(curNode->left);
        PostOrderRecur(curNode->right);
        OutVector.push_back(curNode->number);

        return;
    }

public:
    Node* root = nullptr;
    Node* compare = nullptr;
    vector<int> OutVector;
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    vector<vector<int>> answer;

    for (size_t i = 0; i < nodeinfo.size(); i++) // number 생성
    {
        nodeinfo[i].push_back(i + 1);
    }

    auto lambda = [](vector<int> a, vector<int> b)
        {
            if (*(++a.begin()) > *(++b.begin()))
                return true;

            if (*(++a.begin()) == *(++b.begin()))
            {
                if (a.front() < b.front())
                {
                    return true;
                }
            }

            return false;
        };
    sort(nodeinfo.begin(), nodeinfo.end(), lambda); // y순 x순 정렬

    Tree tree;
    for (size_t i = 0; i < nodeinfo.size(); i++) // number 생성
    {
        tree.Insert(nodeinfo[i]);
    }

    answer.push_back(tree.PreOrder());
    answer.push_back(tree.PostOrder());


    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo;
    nodeinfo = { {5, 3},{11, 5},{13, 3},{3, 5},{6, 1},{1, 3},{8, 6},{7, 2},{2, 2} };

    vector<vector<int>> result = solution(nodeinfo);

    for (auto i : result)
    {
        for (auto j : i)
            cout << j << " ";

        cout << '\n';
    }

}

