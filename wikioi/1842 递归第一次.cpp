#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int work(int x)

{

if (x>=0) return 5;

 else return work(x+1)+work(x+2)+1;

}


int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",work(n));
    while(1);
}
