#include <iostream>
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
node *makeTree(string front, string mid)
{
    if (front == "" || mid == "")
        return nullptr;
    node *root = new node();
    root->val = front[0];
    root->left = nullptr;
    root->right = nullptr;
    char c = front[0];
    string leftMid, rightMid;
    string leftFront, rightFront;
    int leftLen;
    bool r = false;
    for (int i = 0; i < mid.size(); i++)
    {
        if (mid[i] == c)
        {
            leftLen = i;
            r = true;
            continue;
        }
        if (r)
        {
            rightMid += mid[i];
        }
        else
            leftMid += mid[i];
    }
    leftFront = front.substr(1, leftLen);
    rightFront = front.substr(leftLen + 1);
    root->left = makeTree(leftFront, leftMid);
    root->right = makeTree(rightFront, rightMid);
    return root;
}
node *makeTree1(string last, string mid)
{
    if (last == "" || mid == "")
        return nullptr;
    node *root = new node();
    root->val = last[last.size() - 1];
    root->left = nullptr;
    root->right = nullptr;
    char c = last[last.size() - 1];
    string leftMid, rightMid;
    string leftLast, rightLast;
    int leftLen;
    bool r = false;
    for (int i = 0; i < mid.size(); i++)
    {
        if (mid[i] == c)
        {
            leftLen = i;
            r = true;
            continue;
        }
        if (r)
        {
            rightMid += mid[i];
        }
        else
            leftMid += mid[i];
    }
    leftLast = last.substr(0, leftLen);
    rightLast = last.substr(leftLen, last.size() - leftLen - 1);
    root->left = makeTree1(leftLast, leftMid);
    root->right = makeTree1(rightLast, rightMid);
    return root;
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
    string front = "abdhecfg";
    string mid = "dhbeafcg";
    string last = "hdebfgca";
    // node *root = makeTree(front, mid);
    node *root = makeTree1(last, mid);
    cengxu(root);
    system("pause");
    return 0;
}