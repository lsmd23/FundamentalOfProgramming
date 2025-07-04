#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class List
{
public:
    Node *head;
    List()
    {
        head = NULL;
    }
    List(Node *head)
    {
        this->head = head;
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
};

Node *intersect(Node *head1, Node *head2)
{
    Node *temp_ptr_1 = head1;
    Node *temp_ptr_2 = head2;
    List _list;
    while (temp_ptr_1 != NULL && temp_ptr_2 != NULL)
    {
        // while (temp_ptr_2 != NULL)
        // {
        if (temp_ptr_1->data == temp_ptr_2->data)
        {
            _list.insert(temp_ptr_1->data);
            temp_ptr_1 = temp_ptr_1->next;
        }
        else if (temp_ptr_1->data < temp_ptr_2->data)
        {
            temp_ptr_2 = temp_ptr_2->next;
        }
        else
        {
            temp_ptr_1 = temp_ptr_1->next;
        }
        //}
    }
    return _list.head;
}

int main()
{
    int n1, n2;
    List list1, list2;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        list1.insert(x);
    }
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        list2.insert(x);
    }

    List new_list(intersect(list1.head, list2.head));
    new_list.print();
}
