#include <cstdio>
using namespace std;
int ycm=1;
int quan=1;
int dx[5]={0,0,-1,0,1};
int dy[5]={0,1,0,-1,0};
int main()
{
	int map[110][110];
	int n;
	scanf("%d",&n);
	map[n/2+1][n/2+1]=1;
	int kk=1;
	int x=n/2+1;
	int y=x;
	int ans=0;
	int scc=n/2+1;
	while(kk<=n*n-1)
	{
		kk++;
		int nx,ny,lx,ly;
		zhe:
		nx=x+dx[ycm];
		ny=y+dy[ycm];
		lx=nx-scc;
		ly=ny-scc;
		if(ly<0)ly=-ly;
		if(lx<0)lx=-lx;
		if(lx<=quan && ly<=quan && nx>=1 && ny>=1)map[nx][ny]=kk;
		else
		{
			ycm++;
			if(ycm==5)
			{
				quan++;
				ycm=1;
			}
			goto zhe;
		}
		x=nx;
		y=ny;
	}
	for(int i=1;i<=n;i++)
	{
		int j=i;
		ans+=map[i][j];
		j=n-i;
		ans+=map[i][j];
	}
	for(int q=1;q<=n;q++)
	{
		printf("\n");
		for(int w=1;w<=n;w++)
		{
			printf("%d ",map[q][w]);	
		}
	}
	printf("\n%d\n",ans);
	return 0;
}
