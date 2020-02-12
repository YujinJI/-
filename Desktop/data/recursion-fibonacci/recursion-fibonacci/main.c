//
//  main.c
//  recursion-fibonacci
//
//  Created by mac on 2020. 2. 12..
//  Copyright © 2020년 size. All rights reserved.
//

//recursion-fibonacci
#include <stdio.h>
int fib(int n);
int main()
{
    printf("%d\n",fib(5));
}
int fib(int n)
{
    if(n<=0)
        return 0;
    else if(n==1 || n==2)
        return 1;
    else
        return fib(n-2) + fib(n-1);
}
