/* 
合并果子 链接：https://www.acwing.com/problem/content/150/
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        heap.push(a);
    }
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int a1 = heap.top();
        heap.pop();
        int a2 = heap.top();
        heap.pop();
        sum += a1 + a2;
        heap.push(a1 + a2);
    }
    cout << sum << endl;
    return 0;
}