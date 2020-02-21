#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef char element;
element stack[MAX_STACK_SIZE];
int top = -1; //top은 제일 위에원소가 몇번째인지 알려주는 지표(실제 들어있는 원소 -1) 

//공백 상태 검출 함수  
bool is_empty()
{
	if (top==-1){
		return true;
	}
	else
		return false;
}
//포화 상태 검출 함수  
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
//삽입 함수  
void push(element item)
{
	if(is_full()){
		fprintf(stderr,"스택 포화 에러\n");
		return;
	}
	else stack[++top] = item;
}
//삭제 함수
element pop()
{
	if(is_empty()){
		fprintf(stderr,"스택 공백 에러\n");
		exit(1); //exit()함수는 c프로그래밍 자체를 종료  
	}	
	else return stack[top--]; //top원소 return 후 top을 한칸 내려줌  
	//top-- -> top = top - 1(해당 줄 종료 후 적용) 
} 

//
bool check(char *str)
{
	int n;
	n = strlen(str);
	
	for(int i=0;i<n;i++){
		char c = str[i];
		if(c=='(')
			push(c);
		else if(c==')')
		{
			if(is_empty()==true){
			
				//return false;
				printf("FALSE");
				return 0;
			}
			
			else
				pop();
		}
		else
			continue;
	}
	if (is_empty()==true){
		printf("true");
	}
	else
		printf("false");
}

int main(void)
{
	char *ch;
	ch = "(a)()a)";
	
	printf("%c",check(ch));
	
	return 0;
}
