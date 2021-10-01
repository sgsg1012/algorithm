#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void linkSort2(node *&head)
{
    node *cur = head;
    node *p = head->next->next;
    head->next->next = nullptr;
    node *q = p->next;
    while (p != nullptr)
    {
        q = p->next;
        cur = head;
        for (; cur->next != nullptr; cur = cur->next)
        {
            if (cur->next->data < p->data)
                break;
        }
        p->next = cur->next;
        cur->next = p;
        p = q;
    }
}
void linkSort(node *&head)
{
    node *i = nullptr;
    node *ii = nullptr;
    for (ii = head, i = ii->next; i != nullptr; ii = ii->next, i = ii->next)
    {
        node *m = i;
        node *mm = ii;
        for (node *jj = ii, *j = jj->next; j != nullptr; jj = jj->next, j = j->next)
        {
            if (j->data > m->data)
            {
                m = j;
                mm = jj;
            }
        }
        if (i == m)
            continue;
        if (i == mm)
        {
            ii->next = i->next;
            i->next = m->next;
            m->next = i;
            continue;
        }
        ii->next = m;
        node *tem = m->next;
        m->next = i->next;
        mm->next = i;
        i->next = tem;
    }
}
void createLink(node *&head)
{
    head = new node();
    head->next = nullptr;
    head->data = 0;
    int x;
    node *tail = head;
    cin >> x;
    while (x != -1)
    {
        node *tem = new node({x, nullptr});
        tail->next = tem;
        tail = tem;
        head->data++;
        cin >> x;
    }
}
void printLink(node *&head)
{
    node *tem = head->next;
    cout << head->data << endl;
    while (tem != nullptr)
    {
        cout << tem->data << " ";
        tem = tem->next;
    }
    cout << endl;
}
void destoryList(node *&head)
{
    node *tem = head;
    while (tem != nullptr)
    {
        node *p = tem->next;
        delete tem;
        tem = p;
    }
    head = nullptr;
}
int main()
{
    node *head = nullptr;
    createLink(head);
    linkSort2(head);
    printLink(head);
    destoryList(head);
    int x;
    cin >> x;
    return 0;
}