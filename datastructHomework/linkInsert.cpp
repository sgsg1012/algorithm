#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
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
    if (head == nullptr)
        return;
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
    if (head == nullptr)
        return;
    node *tem = head;
    while (tem != nullptr)
    {
        node *p = tem->next;
        delete tem;
        tem = p;
    }
    head = nullptr;
}
void insert(node *&ha, node *&hb, int i)
{
    if (ha == nullptr || hb == nullptr)
        return;
    if (i == 0)
    {
        node *tem = hb;
        while (tem->next != nullptr)
            tem = tem->next;
        tem->next = ha->next;
        hb->data += ha->data;
        ha = nullptr;
        return;
    }
    node *tem = ha;
    for (int j = 1; j <= i && tem->next != nullptr; j++)
    {
        tem = tem->next;
    }
    if (tem->next == nullptr)
    {
        tem->next = hb->next;
        ha->data += hb->data;
        hb = nullptr;
        return;
    }
    node *p = tem->next;
    tem->next = hb->next;
    while (tem->next != nullptr)
        tem = tem->next;
    tem->next = p;
    ha->data += hb->data;
    hb = nullptr;
}
int main()
{
    while (true)
    {
        node *ha = nullptr;
        node *hb = nullptr;
        // createLink(ha);
        // createLink(hb);
        // insert(ha, hb, 0);
        // insert(ha, hb, 3);
        insert(ha, hb, 100);
        printLink(ha);
        printLink(hb);
        destoryList(ha);
        destoryList(hb);
    }
    return 0;
}