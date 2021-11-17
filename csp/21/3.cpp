#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
typedef unsigned long long ull;
struct node
{
    bool type; //0--文件夹 1--文件
    string name;
    ull cap1;
    ull cap2;
    ull size1;
    ull size2;
    ull size;
    vector<node *> sons;
    node *father;
};
vector<string> split(string str)
{
    vector<string> res;
    int i = 0;
    while (i < str.size())
    {
        string s;
        int j = i;
        for (; j < str.size(); j++)
        {
            if (str[j] == '/')
            {
                break;
            }
            s += str[j];
        }
        i = j + 1;
        if (s != "")
            res.push_back(s);
    }
}
node *root = new node();

int main()
{
    srand((int)time(0));
    int n;
    cin >> n;
    string op;
    root->type = 0;
    root->name = "/";
    root->cap1 = 0;
    root->cap2 = 0;
    root->size1 = 0;
    root->size2 = 0;
    root->father = nullptr;
    while (n--)
    {
        cin >> op;
        if (op == "C")
        {
        }
        else if (op == "R")
        {
        }
        else if (op == "Q")
        {
        }
        int res = rand() % 2;
        if (res)
        {
            cout << "Y" << endl;
        }
        else
            cout << "N" << endl;
    }
    return 0;
}