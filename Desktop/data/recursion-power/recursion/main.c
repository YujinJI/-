//
//  main.c
//  recursion
//
//  Created by mac on 2020. 2. 12..
//  Copyright © 2020년 size. All rights reserved.
//

//recursion
#include <stdio.h>
int main()
{
    int n;
    printf("밑 입력:");
    scanf("%d",&n);
    
    int z;
    printf("지수 입력:");
    scanf("%d",&z);
    
    int power(int n,int z);
    printf("%d\n",power(n,z));
}
int power(int un,int ov)
{
    if(ov<=0)
        return 1;
    else
        return un * power(un,ov-1);
}
