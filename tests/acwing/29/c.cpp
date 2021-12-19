/* https://www.acwing.com/problem/content/4199/ */
/*  模板题 记录一下路径而已
    dijkstra和spfa都能过
    图论好难。。。
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node
{
  unsigned long long dist;
  int idx;
  int father;
  bool operator<(node a)const
  {
      return dist>a.dist;
  }
};
vector<int> ans;
const int N = 100010;
int h[N],e[N*2],ne[N*2],w[N*2];
int idx;
int n,m;
bool st[N];
int father[N];
void add(int x,int y,int z)
{
    e[idx]=y;
    ne[idx]=h[x];
    w[idx]=z;
    h[x]=idx++;
}
bool dijkstra()
{
    priority_queue<node> q;
    node t;
    t.idx=1;
    t.dist=0;
    t.father=0;
    q.push(t);
    while(q.size())
    {
        auto t=q.top();
        q.pop();
        if(st[t.idx]) continue;
        father[t.idx]=t.father;
        st[t.idx]=true;
        if(t.idx==n)
        {
            ans.push_back(n);
            int last=father[n];
            while(last) 
            {
                ans.push_back(last);
                last=father[last];
            }
            return true;
        }
        for(int i=h[t.idx];i!=-1;i=ne[i])
        {
            int j=e[i];
            node p;
            p.idx=j;
            p.dist=t.dist+w[i];
            p.father=t.idx;
            q.push(p);
        }
    }
    return false;
}
int main()
{
    for(int i=0;i<N;i++) h[i]=-1;
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    if(dijkstra())
    {
        for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
        cout<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}