#include<stdio.h>
#define MAX 100
int top = -1;
char stack[100];
void push(char val){
	if(top == MAX - 1){
		//checking stack is filled or not
		printf("Stack if filled\n");
//		return;
	}	
	top++;
	stack[top] = val;
}
void pop(){
	
		if(top == -1){
			printf("Stack is empty\n");
//			return;
		}
		else{
			//int res = stack[top];
			top--;
			}		
}
int Empty(){
	if(top == -1)	return 1;
	else return 0;
}
char Top(){
	if(top == -1){
		printf("Stack is empty\n");
	}
	else	return stack[top];
}
int	Size(){
		return top + 1;
	}

int main(){
	char *str = "{(([])[])[]}[]";
	int flage = 1;
	for(int i = 0; str[i] != '\0'; i++){
		
		if(str[i] == '(' || str[i] == '{' || str[i] == '['){
			push(str[i]);
		}
		else{
			if(str[i] == ')' && !Empty() && Top() == '('){
				pop();
			}
			else if(str[i] == '}' && !Empty() && Top() == '{'){
				pop();
			}
			else if(str[i] == ']' && !Empty() && Top() == '['){
				pop();
			}
			else{
				flage = 0;
				break;
			}
		}
	}
	if(flage == 1)	printf("Valid\n");
	else	printf("Not Valid\n");
	
}