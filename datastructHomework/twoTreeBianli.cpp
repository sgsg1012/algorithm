#include <iostream>
#include <unordered_map>
#include <stack>
#include <queue>
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
void firstRoot(node *root)
{
    unordered_map<char, int> m;
    stack<node *> stk;
    node *p = root;
    stk.push(root);
    while (p != nullptr)
    {
        // node *p = stk.top();
        if (m.count(p->val) == 0)
        {
            cout << p->val << " ";
            m[p->val] = 1;
        }
        if (p->left != nullptr && m.count(p->left->val) == 0)
        {
            stk.push(p->left);
            p = p->left;
        }
        else if (p->right != nullptr && m.count(p->right->val) == 0)
        {
            stk.push(p->right);
            p = p->right;
        }
        else
        {
            stk.pop();
            if (stk.empty())
                p = nullptr;
            else
                p = stk.top();
        }
    }
    cout << endl;
}
void midRoot(node *root)
{
    unordered_map<char, int> m;
    stack<node *> stk;
    node *p = root;
    stk.push(root);
    while (p != nullptr)
    {
        // node *p = stk.top();
        if (p->left != nullptr && m.count(p->left->val) == 0)
        {
            stk.push(p->left);
            p = p->left;
        }
        else
        {
            if (m.count(p->val) == 0)
            {
                cout << p->val << " ";
                m[p->val] = 1;
            }
            if (p->right != nullptr && m.count(p->right->val) == 0)
            {
                stk.push(p->right);
                p = p->right;
            }
            else
            {
                stk.pop();
                if (stk.empty())
                    p = nullptr;
                else
                    p = stk.top();
            }
        }
    }
    cout << endl;
}
void lastRoot(node *root)
{
    unordered_map<char, int> m;
    stack<node *> stk;
    node *p = root;
    stk.push(root);
    while (p != nullptr)
    {
        // node *p = stk.top();
        if (p->left != nullptr && m.count(p->left->val) == 0)
        {
            stk.push(p->left);
            p = p->left;
        }
        else
        {
            if (p->right != nullptr && m.count(p->right->val) == 0)
            {
                stk.push(p->right);
                p = p->right;
            }
            else
            {
                if (m.count(p->val) == 0)
                {
                    cout << p->val << " ";
                    m[p->val] = 1;
                }
                stk.pop();
                if (stk.empty())
                    p = nullptr;
                else
                    p = stk.top();
            }
        }
    }
    cout << endl;
}
void cengxu(node *root)
{
    queue<node *> q;
    q.push(root);
    while (q.size())
    {
        int len = q.size();
        while (len--)
        {
            node *p = q.front();
            q.pop();
            cout << p->val << " ";
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
    }
    cout << endl;
}
int main()
{
    string s = "a(b(d(,h),e),c(f,g))";
    node *root = createTree(s);
    // printTree(root);
    firstRoot(root);
    midRoot(root);
    lastRoot(root);
    cengxu(root);
    system("pause");
    return 0;
}