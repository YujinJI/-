#include <stdio.h>
int fib(int n)
{
    int p = 1;
    int pp = 0;
    int result = 0;
    
    if(n==0)
    	return 0;
    if(n==1)
    	return 1;
    
    for(int i=2;i<=n;i++)
    {
    	result = pp + p;
    	pp = p;
    	p = result;
	}
	return result;
} 
int main(void)
{
	printf("%d\n",fib(5));
}
