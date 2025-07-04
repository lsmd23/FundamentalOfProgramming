#include <iostream>

using namespace std;

struct Polynomial
{
    int coef;
    int exp;
    Polynomial *next;
};

bool isZero(Polynomial *node)
{
    return node->coef == 0;
}

int polynomialLength(Polynomial *head)
{
    Polynomial *p = head->next;
    int length = 0;
    while (p != nullptr)
    {
        if (!isZero(p))
            length++;
        p = p->next;
    }
    return length;
}

void createPolynomial(Polynomial *head, int n)
{
    Polynomial *p = head;
    for (int i = 0; i < n; i++)
    {
        int _coef, _exp;
        cin >> _coef >> _exp;
        Polynomial *temp = new Polynomial;
        temp->coef = _coef;
        temp->exp = _exp;
        p->next = temp;
        p = temp;
    }
    p->next = nullptr;
}

void printPolynomial(Polynomial *head)
{
    cout << polynomialLength(head) << endl;
    Polynomial *p = head->next;
    p = head->next;
    while (p != nullptr)
    {
        if (!isZero(p))
            cout << p->coef << " " << p->exp << endl;
        p = p->next;
    }
}

void addPolynomial(Polynomial *head1,
                   Polynomial *head2,
                   Polynomial *resultHead)
{
    Polynomial *p1 = head1->next;
    Polynomial *p2 = head2->next;
    Polynomial *p = resultHead;
    while (p1 != nullptr || p2 != nullptr)
    {
        if (p1 != nullptr && p2 != nullptr)
        {
            if (p1->exp < p2->exp)
            {
                p->next = new Polynomial;
                p = p->next;
                p->coef = p1->coef;
                p->exp = p1->exp;
                p1 = p1->next;
            }
            else if (p1->exp > p2->exp)
            {
                p->next = new Polynomial;
                p = p->next;
                p->coef = p2->coef;
                p->exp = p2->exp;
                p2 = p2->next;
            }
            else
            {
                p->next = new Polynomial;
                p = p->next;
                p->coef = p1->coef + p2->coef;
                p->exp = p1->exp;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        else if (p1 == nullptr && p2 != nullptr)
        {
            p->next = new Polynomial;
            p = p->next;
            p->coef = p2->coef;
            p->exp = p2->exp;
            p2 = p2->next;
        }
        else if (p2 == nullptr && p1 != nullptr)
        {
            p->next = new Polynomial;
            p = p->next;
            p->coef = p1->coef;
            p->exp = p1->exp;
            p1 = p1->next;
        }
        else
            break;
    }
    p->next = nullptr;
}

int main()
{
    int m, n;

    cin >> m;
    Polynomial *head1 = new Polynomial;
    createPolynomial(head1, m);

    cin >> n;
    Polynomial *head2 = new Polynomial;
    createPolynomial(head2, n);

    Polynomial *resultHead = new Polynomial;
    addPolynomial(head1, head2, resultHead);

    printPolynomial(resultHead);

    return 0;
}