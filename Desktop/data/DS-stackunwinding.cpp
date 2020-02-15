#include <stdio.h>

void func2(){
	printf("called func2");
}
void func1(){
	func2();
	printf("called func1");
}

int main(){
	func1();
}
