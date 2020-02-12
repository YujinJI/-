//
//  main.c
//  recursion-factorial
//
//  Created by mac on 2020. 2. 12..
//  Copyright © 2020년 size. All rights reserved.
//

//recursion-factorial
#include <stdio.h>
int fact(int a);
int main()
{
    int n;
    printf("%d\n",fact(5));
}
int fact(int a)
{
    if(a<=1)
        return 1;
    else
        return a * fact(a-1);
}
