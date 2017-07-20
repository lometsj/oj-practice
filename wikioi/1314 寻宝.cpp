#include <cstdio>

using namespace std;

int n,m;
int ans=0;
struct node
{
	int door;
	int flag;
}a[100010][110];
int getin;
int b[100010][110];
int scc=0;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scc=1;
		for(int j=1;j<=m;j++)
		{
			scanf("%d %d",&a[i][j].door,&a[i][j].flag);
			if(a[i][j].door)
			{
				b[i][scc++]=j;
			}
		}
		b[i][109]=scc-1;
	}
	scanf("%d",&getin);
	getin++;
	
	for(int i=1;i<=n;i++)
	{
		ans+=a[i][getin].flag;
		ans%=20123;
		int x=a[i][getin].flag;
		for(int j=getin;;j++)
		{
			if(j>m)j-=m;
			if(a[i][j].door)
			{
				getin=j;
				x--;
				break;
			}
		}
		if(!x)continue;
		int y;
		for(int j=1;j<=b[i][109];j++)
		{
			if(b[i][j]==getin)
			{
				y=j;
				break;
			}
		}
		int z=(x+y)%b[i][109];
		if(!z)z=b[i][109];
		getin=b[i][z];
	}
	printf("%d\n",ans);
	return 0;
} 
