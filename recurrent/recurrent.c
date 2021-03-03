#include <stdio.h>
#include <windows.h>

int add(int n)
{
    if( 1==n ) return 1;
    else return add(n-1) + n;
}
int factorial(int n)
{
    if( 1==n ) return 1;
    else return factorial(n-1) * n;
}
int main(void)
{
    printf("%d\n", add(100));
    printf("%d\n", factorial(5));
    system("pause");
    return 0;
}