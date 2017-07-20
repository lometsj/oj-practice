#include <cstdio>

//int x();

int &f()
{
	int x;
	return x;
}

int main()
{
	int a;
	printf("%d",sizeof(a));
}
