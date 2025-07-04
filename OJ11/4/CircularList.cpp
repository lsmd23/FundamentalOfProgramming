#include <iostream>

using namespace std;

struct CircularListNode
{
    int data;
    CircularListNode *next;
    CircularListNode(int _data) : data(_data), next(nullptr) {}
    CircularListNode(int _data, CircularListNode *_next) : data(_data), next(_next) {}
};

class CircularList
{
    int size;
    CircularListNode *top = nullptr;

public:
    CircularList(int _size) : size(_size)
    {
        CircularListNode *temp = top;
        for (int i = 1; i <= size; i++)
        {
            CircularListNode *new_node = new CircularListNode(i);
            if (top == nullptr)
            {
                top = new_node;
                top->next = nullptr;
                temp = top;
            }
            else
            {
                temp->next = new_node;
                temp = temp->next;
            }
        }
        temp->next = top;
    }
    int select(int random_number)
    {
        while (size > 1)
        {
            for (int i = 0; i < random_number - 2; i++)
            {
                top = top->next;
            }
            // 找到要删除的前一个节点
            CircularListNode *temp = top->next;
            top->next = temp->next;
            delete temp;
            // 删除节点
            top = top->next;
            size--;
        }
        return top->data;
    }
};

int main()
{
    int n;
    cin >> n;
    CircularList list(n);

    int m;
    cin >> m;
    cout << list.select(m) << endl;
    return 0;
}