#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

struct yang
{
    int v;
    int next;
}a1[100002],a2[100002];
int b[100005];
int scc,cnt;
int n,m;
int f1[10002];
int f2[10002];
int dfn[10002];
bool inx1[10002];
bool inx2[10002];
int color[100005];
int max[100005],min[100005];
int d[100005];
void dfs1(int k)
{
    inx1[k]=1;
    for(int i=f1[k];i!=-1;i=a1[i].next)
    {
        if(!inx1[a1[i].v])
        {
            dfs1(a1[i].v);
        }

    }
    dfn[++cnt]=k;
}

void dfs2(int k,int i)
{
    max[i]>?b[i];
    min[i]<?b[i];
    color[k]=i;
    inx2[k]=1;
    for(int i=f2[k];i!=-1;i=a2[i].next)
    {
        if(inx2[a2[i].v]==0)
        {
            dfs2(a2[i].v);
        }
    }
}

int main()
{
    freopen("trade.in","r",stdin);
    freopen("trade.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        f1[i]=-1;
        f2[i]=-1;
    }
    for(int i=1;i<=m;i++)
    {
        int z=-1,x,y;
        scanf("%d %d %d",&x,&y,&z);
        //printf("%d %d %d\n",x,y,z);
        if(z==1)
        {
            a1[k].v=y;
            a2[k].v=x;
            a1[k].next=f[x];
            a2[k].next=f[y];
            f1[x]=k;
            f2[y]=k;
            k++;
        }
        if(z==2)
        {
            a1[k].v=y;
            a2[k].v=x;
            a1[k].next=f[x];
            a2[k].next=f[y];
            f1[x]=k;
            f2[y]=k;
            k++;

            a1[k].v=x;
            a2[k].v=y;
            a1[k].next=f[y];
            a2[k].next=f[x];
            f1[y]=k;
            f2[x]=k;
            k++;
        }
    }
    cnt=0;
    scc=0;
    for(int i=1;i<=n;i++)
    {
        if(!inx1[i])  dfs1(i);
    }
    for(int i=cnt;i>=1;i--)
    {
        if(!inx2[dfn[i]])
        {
            max[i]=-1;min[i]=1000000000;
            dfs2(dfn[i],i);
            scc++;
        }
    }
    bool in[100005];
    for(int i=1;i<=n;i++)
    {
        d[i]=1000000000;
        in[i]=0;
    }
    d[1]=0;
    queue<int >q;
    q.push(1);
    while(q.empty())
    {
        int x=q.front();q.pop();
        in[x]=1;
        for(int e=f1[x];e!=-1;e=a[e].next)
        {
            d[]
        }
    }
}
