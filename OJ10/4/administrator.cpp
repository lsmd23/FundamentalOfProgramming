#include <iostream>

using namespace std;

struct user
{
    int id;
    user *next;
};

void createUserList(user *head, int n)
{
    user *p = head;
    for (int i = 0; i < n; i++)
    {
        int _id;
        cin >> _id;
        user *temp = new user;
        temp->id = _id;
        temp->next = NULL; // 初始化新节点的 next 指针
        p->next = temp;
        p = temp;
    }
}

void insertUser(user *head, int id)
{
    user *p = head;
    while (p->next != NULL && p->next->id < id)
    {
        p = p->next;
    }
    user *temp = new user;
    temp->id = id;
    temp->next = p->next;
    p->next = temp;
}

void deleteUser(user *head, int id)
{
    user *p = head;
    while (p->next != NULL)
    {
        if (p->next->id == id)
        {
            user *temp = p->next;
            p->next = p->next->next;
            delete temp;
            break;
        }
        else
        {
            p = p->next;
        }
    }
}

void printUserList(user *head)
{
    user *p = head->next;
    while (p != NULL)
    {
        cout << p->id << endl;
        p = p->next;
    }
}

void deleteList(user *head)
{
    user *p = head;
    while (p != NULL)
    {
        user *temp = p;
        p = p->next;
        delete temp;
    }
}

int main()
{
    int m, n;
    cin >> m;
    user *head1 = new user;
    head1->next = NULL; // 初始化头节点的 next 指针
    createUserList(head1, m);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int _id, _operator;
        cin >> _id >> _operator;
        if (_operator)
        {
            insertUser(head1, _id);
        }
        else
        {
            deleteUser(head1, _id);
        }
    }

    printUserList(head1);

    deleteList(head1);

    return 0;
}