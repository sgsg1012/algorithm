#include <iostream>
using namespace std;
const int N = 100100;
struct node
{
    int val;
    int next;
};
node seq[N];
int h = -1;
int idx = 1;
void insert(int x)
{
    seq[idx].val = x;
    seq[idx].next = h;
    h = idx;
    idx++;
}
void remove(int k)
{
    if (k == 0)
    {
        h = seq[h].next;
    }
    seq[k].next = seq[seq[k].next].next;
}
void kinsert(int k, int x)
{
    seq[idx].val = x;
    seq[idx].next = seq[k].next;
    seq[k].next = idx;
    idx++;
}
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        string op;
        cin >> op;
        int k, x;
        if (op == "H")
        {
            cin >> x;
            insert(x);
        }
        else if (op == "D")
        {
            cin >> k;
            remove(k);
        }
        else
        {
            cin >> k >> x;
            kinsert(k, x);
        }
    }
    for (int i = h; i != -1; i = seq[i].next)
    {
        cout << seq[i].val << " ";
    }
    cout << endl;
    return 0;
}