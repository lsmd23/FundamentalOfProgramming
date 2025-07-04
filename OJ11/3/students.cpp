#include <iostream>

using namespace std;

struct Student
{
    int id;
    string name;
    string gender;
    int score;
};

struct Node
{
    Student data;
    Node *next;
};

void insertStudent(Node *head, Student student)
{
    Node *p = head;
    if (p->next == nullptr)
    {
        Node *temp = new Node;
        temp->data = student;
        temp->next = nullptr;
        head->next = temp;
        return;
    }
    while (p->next != nullptr &&
           (p->next->data.score > student.score ||
            (p->next->data.score == student.score && p->next->data.id < student.id)))
    {
        p = p->next;
    }
    Node *temp = new Node;
    temp->data = student;
    temp->next = p->next;
    p->next = temp;
} // 在链表中插入一个节点,使得链表按照分数从高到低排列

int deleteStudentScore(int rank, Node *head)
{

    Node *p = head;
    int rank_score = -1;
    for (int i = 0; i < rank; i++)
    {
        p = p->next;
    }
    // 找到了第 rank 个节点为 p
    rank_score = p->data.score;
    return rank_score;
} // 返回该节点的分数

int deleteStudent(int score, Node *head)
{
    Node *p = head;
    while (p->next != nullptr)
    {
        if (p->next->data.score == score)
        {
            Node *temp = p->next;
            p->next = p->next->next;
            delete temp;
        }
        else
        {
            p = p->next;
        }
    }
} // 删除链表中所有分数为 score 的节点

int main()
{
    int n;
    cin >> n;

    Node *head = new Node;
    head->next = nullptr;
    for (int i = 0; i < n; i++)
    {
        Student student;
        cin >> student.id >> student.name >> student.gender >> student.score;
        insertStudent(head, student);
    }

    int m;
    cin >> m;
    int score[m];
    for (int i = 0; i < m; i++)
    {
        int rank;
        string cmd;
        cin >> cmd >> rank;
        score[i] = deleteStudentScore(rank, head);
    }

    for (int i = 0; i < m; i++)
    {
        deleteStudent(score[i], head);
    }

    Node *p = head->next;
    while (p != nullptr)
    {
        cout << p->data.id << " " << p->data.name << " " << p->data.gender << " " << p->data.score << endl;
        p = p->next;
    }

    return 0;
}