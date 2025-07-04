#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class List
{
private:
    Node *head;

public:
    List()
    {
        head = NULL;
    }
    void insert(int x)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = head;
        head = temp;
    } // insert node at the beginning of the list
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    } // print the list from head to tail
    void removeDuplicates()
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->data == temp->next->data)
            {
                Node *del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            else
            {
                temp = temp->next;
            }
        } // remove duplicates from the list
    };
};

int main()
{
    int n;
    cin >> n;
    stack<int> s;
    List list;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push(x);
    } // input elements to stack
    while (!s.empty())
    {
        list.insert(s.top());
        s.pop();
    } // insert elements from stack to list
    list.removeDuplicates();
    list.print();
    return 0;
}