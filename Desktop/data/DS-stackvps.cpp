#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef char element;
element stack[MAX_STACK_SIZE];
int top = -1; //top�� ���� �������Ұ� ���°���� �˷��ִ� ��ǥ(���� ����ִ� ���� -1) 

//���� ���� ���� �Լ�  
bool is_empty()
{
	if (top==-1){
		return true;
	}
	else
		return false;
}
//��ȭ ���� ���� �Լ�  
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}
//���� �Լ�  
void push(element item)
{
	if(is_full()){
		fprintf(stderr,"���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}
//���� �Լ�
element pop()
{
	if(is_empty()){
		fprintf(stderr,"���� ���� ����\n");
		exit(1); //exit()�Լ��� c���α׷��� ��ü�� ����  
	}	
	else return stack[top--]; //top���� return �� top�� ��ĭ ������  
	//top-- -> top = top - 1(�ش� �� ���� �� ����) 
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
