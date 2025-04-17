// 029.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    Node(int InValue) :value(InValue) {}

    int value;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BinarySearchTree
{
public:
    ~BinarySearchTree()
    {
        DeleteAll(root);
    }

    void Insert(int InValue)
    {
        if (root == nullptr)
        {
            Node* NewNode = new Node(InValue);
            root = NewNode;
            return;
        }

        Node* temp = Find(InValue, root);
        if (temp != nullptr) // 중복된 값이 있는 경우
            return;

        Insert(InValue, root);
    }

    bool Find(int InValue)
    {
        if (root == nullptr)
        {
            return false;
        }

        Node* result = Find(InValue, root);
        if (result == nullptr)
            return false;
        else
            return true;
    }

private:
    void Insert(int InValue, Node* CurrentNode)
    {
        if (CurrentNode->value > InValue)
        {
            if (CurrentNode->left == nullptr)
            {
                Node* NewNode = new Node(InValue);
                CurrentNode->left = NewNode;
                return;
            }
            else
            {
                Insert(InValue, CurrentNode->left);
            }
        }
        else
        {
            if (CurrentNode->right == nullptr)
            {
                Node* NewNode = new Node(InValue);
                CurrentNode->right = NewNode;
                return;
            }
            else
            {
                Insert(InValue, CurrentNode->right);
            }
        }

    }

    Node* Find(int InValue, Node* CurrentNode)
    {
        if (CurrentNode->value == InValue)
            return CurrentNode;

        else if (CurrentNode->value > InValue)
        {
            if (CurrentNode->left == nullptr)
            {
                return nullptr;
            }
            else
            {
                return Find(InValue, CurrentNode->left);
            }
        }
        else
        {
            if (CurrentNode->right == nullptr)
            {
                return nullptr;
            }
            else
            {
                return Find(InValue, CurrentNode->right);
            }
        }
    }

    void DeleteAll(Node* CurrentNode)
    {
        if (CurrentNode == nullptr) 
            return;

        DeleteAll(CurrentNode->left);
        DeleteAll(CurrentNode->right);
        delete CurrentNode;
    }



private:
    Node* root = nullptr;
};

vector<bool> solution(vector<int> lst, vector<int> search_lst)
{
    vector<bool> answer;

    BinarySearchTree bst;
    
    for (size_t i = 0; i < lst.size(); i++)
    {
        bst.Insert(lst[i]);
    }

    for (size_t i = 0; i < search_lst.size(); i++)
    {
        answer.push_back(bst.Find(search_lst[i]));
    }

    return answer;
}

int main()
{
    vector<int> lst = { 5, 3, 8, 4, 2, 1, 7, 10};
    vector<int> search_lst = { 1, 2, 5, 6};

    //vector<int> lst = { 1, 3, 5, 7, 9 };
    //vector<int> search_lst = { 2, 4, 6, 8, 10 };

    vector<bool> result;
    result = solution(lst, search_lst);
    for (auto b : result)
        cout << b << " ";

}
