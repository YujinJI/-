//
//  main.c
//  swap
//
//  Created by mac on 2020. 2. 12..
//  Copyright © 2020년 size. All rights reserved.
//

//포인터를 이용하여 swap
#include <stdio.h>
void swap(int *a,int *b);
int main()
{
    int c=100,d=200;
    swap(&c,&d);
    printf("%d %d",c,d);
}
void swap(int *a,int *b)
{
    int *tmp = NULL;
    *tmp = *a;
    *a = *b;
    *b = *tmp;
}
