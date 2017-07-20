#include <cstdio>
#include <iostream>
#include <cmath>
#include <stack>
using namespace std;
stack<int >a,b,c;
void h(int n,int f,int u,int t)
{
	if(n==1)
	{
		int x;
		if(f==1)
		{
			x=a.top();
			a.pop();
		}
		if(f==2)
		{
			x=b.top();
			b.pop();
		}
		if(f==3)
		{
			x=c.top();
			c.pop();
		}
		if(t==1)
		{
			a.push(x);
		}
		if(t==2)
		{
			b.push(x);
		}
		if(t==3)
		{
			c.push(x);
		}
		printf("%d from %c to %c\n",x,f+64,t+64);
	}
	else
	{
		h(n-1,f,t,u);
		h(1,f,u,t);
		h(n-1,u,f,t);
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	for(int i=n;i>=1;i--)
	{
		a.push(i);
	}
	printf("%0.f\n",pow(2.0,n)-1);
	h(n,1,2,3);
	return 0;
}
