#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void initStack(node *&t)
{
    t = new node({0, nullptr});
}
void createStack(node *&t)
{
    t = new node({0, nullptr});
    int x;
    cin >> x;
    while (x != -1)
    {
        node *tem = new node({x, nullptr});
        t->data++;
        tem->next = t->next;
        t->next = tem;
    }
}
void pushStack(node *&t, int x)
{
    node *tem = new node({x, nullptr});
    t->data++;
    tem->next = t->next;
    t->next = tem;
}
void popStack(node *&t, int &x)
{
    x = t->next->data;
    node *p = t->next;
    t->next = t->next->next;
    t->data--;
    delete p;
    p = nullptr;
}
int main()
{
    node *t = nullptr;
    initStack(t);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            pushStack(t, s[i]);
        }
        else
        {
            int x = 0;
            popStack(t, x);
            if (s[i] == ')')
            {
                if (x != (int)'(')
                {
                    cout << "no" << endl;
                    return 0;
                }
            }
            else if (s[i] == ']')
            {
                if (x != (int)'[')
                {
                    cout << "no" << endl;
                    return 0;
                }
            }
            else if (s[i] == '}')
            {
                if (x != (int)'{')
                {
                    cout << "no" << endl;
                    return 0;
                }
            }
        }
    }
    if (t->data != 0)
    {
        cout << "no" << endl;
        return 0;
    }
    cout << "yes" << endl;
    int x;
    cin >> x;
    return 0;
}