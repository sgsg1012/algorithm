#include <iostream>
using namespace std;
struct node
{
    char val;
    node *left;
    node *right;
};
node *createTree(string s)
{
    if (s == "")
        return nullptr;
    node *root = new node();
    root->val = s[0];
    root->left = nullptr;
    root->right = nullptr;
    string left, right;
    bool r = false;
    int num = 0;
    for (int i = 2; i < s.size() - 1; i++)
    {
        if (s[i] == '(')
            num++;
        if (s[i] == ')')
            num--;
        if (s[i] == ',' && num == 0)
        {
            r = true;
            continue;
        }
        if (r)
        {
            right += s[i];
        }
        else
            left += s[i];
    }
    root->left = createTree(left);
    root->right = createTree(right);
    return root;
}
void destoryTree(node *root)
{
    if (root == nullptr)
        return;
    destoryTree(root->left);
    destoryTree(root->right);
    delete root;
}
node *findElement(node *root, char c)
{
    if (root == nullptr)
        return nullptr;
    if (root->val == c)
        return root;
    node *res = findElement(root->left, c);
    if (res != nullptr)
        return res;
    return findElement(root->right, c);
}
int calHeight(node *root)
{
    if (root == nullptr)
        return 0;
    return max(calHeight(root->left), calHeight(root->right)) + 1;
}
void printTree(node *root)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->val;
        return;
    }
    cout << root->val << "(";
    printTree(root->left);
    cout << ",";
    printTree(root->right);
    cout << ")";
}
int main()
{
    string s = "a(b(d(,h),e),c(f,g))";
    node *root = createTree(s);
    printTree(root);
    cout << endl;
    system("pause");
    return 0;
}