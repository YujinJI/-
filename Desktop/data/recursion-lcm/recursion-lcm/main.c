//
//  main.c
//  recursion-lcm
//
//  Created by mac on 2020. 2. 12..
//  Copyright © 2020년 size. All rights reserved.
//

//recursion-lcm
//유클리드 호제법이용
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
int lcm(int c,int d)
{
    return (c / gcd(c,d)) * (d / gcd(c,d)) * gcd(c,d);
}
int main()
{
    printf("최대공약수:%d\n",gcd(8,6));
    printf("최소공배수:%d\n",lcm(8,6));
}
