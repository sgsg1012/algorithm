/* https://www.acwing.com/problem/content/4197/ */
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    int n,t;cin>>n>>t;
    cout<<fixed<<setprecision(6)<<n*pow(1.00011,t)<<endl;
    return 0;
}