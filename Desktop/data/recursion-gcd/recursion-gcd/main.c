//
//  main.c
//  recursion-gcd
//
//  Created by mac on 2020. 2. 12..
//  Copyright © 2020년 size. All rights reserved.
//

//recursion-gcd
#include <stdio.h>
int gcd(int a,int b)
{
    if(a<b)
        return gcd(b,a); //왼쪽인자가 오른쪽인자보다 크다는것을 보장
    if(b==0)
        return a;
    else
        return gcd(a%b,b);
    
}
int main()
{
    printf("%d\n",gcd(12,4));
}
