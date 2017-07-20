#include <cstdio>

using namespace std;

int main()
{
    int a1,b1,c1,a2,b2,c2;
    scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2);
    int d=a1*b2-a2*b1;
    int d1=c1*b2-c2*b1; 
    int d2=a1*c2-a2*c1;

    printf("x=%d\ny=%d",d1/d,d2/d);
    while(1);
    return 0;
}
