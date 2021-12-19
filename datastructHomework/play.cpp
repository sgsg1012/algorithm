#include <iostream>
using namespace std;
const int Max = 10;
struct node
{
    int val;
    node *sons[Max];
};
int calHeight(node *root)
{
    if (root == nullptr)
        return 0;
    int height = 1;
    for (int i = 0; i < Max; i++)
    {
        if (root->sons[i] != nullptr)
        {
            height = max(height, calHeight(root->sons[i]) + 1);
        }
    }
    return height;
}
int main()
{
    node *n = new node();
    cout << n->val << endl;
    for (int i = 0; i < Max; i++)
    {
        cout << n->sons[i] << endl;
    }
    system("pause");
    return 0;
}