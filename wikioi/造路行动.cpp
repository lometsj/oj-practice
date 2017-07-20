#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,u[1002],v[1002],w[1002];
int que[1002];
int ans=0;
int f[1002];

struct edge
{
    int u,v,w;
    friend bool operator < (edge a,edge b)
    {
        return a.w < b.w;
    }
}a[1000*1000];

int find(int x)
{
    if(f[x]==x)return x;
    else return f[x]=find(f[x]);
}

void he(int x,int y,int w)
{
    int fx=find(x);
    int fy=find(y);
    f[fx]=fy;
    ans+=w;
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        f[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    }
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++)
    {
        if(find(a[i].u)!=find(a[i].v))
        {
            he(a[i].u,a[i].v,a[i].w);
        }
    }
    printf("%d",ans);
  //  while(1);
    return 0;
}
