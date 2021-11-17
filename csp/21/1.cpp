#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    while (n--)
    {
        int w;
        int score;
        cin >> w >> score;
        sum += w * score;
    }
    cout << max(0, sum) << endl;
    return 0;
}