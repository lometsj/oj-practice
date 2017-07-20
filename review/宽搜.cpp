#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int x,y,step;
}start,end;
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};
int n,m;
int a[2500][2500];
queue<node >q;

int main()
{
	freopen("ฟํหั.in","r",stdin);
    freopen("ฟํหั.out","w",stdout);
	int x1,x2,y1,y2;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		int s;
		scanf("%d",&s);
		if(s==0)a[i][j]=0;
		else a[i][j]=1;
	}
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	start.x=x2;
	start.y=y2;
	end.x=x1;
	end.y=y1;
	start.step=0;
	q.push(start);
	a[x2][y2]=1;
	while(!q.empty())
	{
		node cs=q.front();q.pop();
		//printf("%d %d\n",cs.x,cs.y);
		for(int i=1;i<=4;i++)
		{
			node ns=cs;
			ns.x=cs.x+dx[i];
			ns.y=cs.y+dy[i];
			//printf("%d %d\n",ns.x,ns.y);
			if(ns.x==end.x && ns.y==end.y)
			{
				//printf("end:%d %d\n",end.x,end.y);
				printf("%d\n",ns.step+1);
				return 0;
			}
			if(ns.x>=1 && ns.y>=1 && ns.x<=n && ns.y<=m && a[ns.x][ns.y]!=1)
			{
				a[ns.x][ns.y]=1;
				ns.step++;
				q.push(ns);
			}
		}
	}
	printf("No Answer!");
	return 0;
}
