/* https://www.acwing.com/problem/content/4198/ */
/* 扫描线或者差分
    扫描线还没看，头疼
    差分想到了，但是感觉数组开不了这么大。。。
    没想到是用map来进行前缀和，学到了
 */
#include<iostream>
#include<map>
using namespace std;
const int N = 200010;
long long ans[N];
int main()
{
    int n;cin>>n;
    map<long long , int> m;
    long long a,b;
    int num=n;
    while(num--)
    {
        scanf("%lld%lld",&a,&b);
        m[a]++;
        m[b+1]--;
    }
    long long  sum=0,last=-1;
    for(auto& [x,y]:m)
    {
        if(last!=-1) ans[sum]+=(x-last);
        sum+=y;
        last=x;
    }
    
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    
    return 0;
}