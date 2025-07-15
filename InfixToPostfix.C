//Infix to postfix

#include<stdio.h>
#define max 100
char stack[max];
int top = -1;
void push(char val){
	if(top == max - 1)	return;
	stack[++top] = val;
}
void pop(){
	if(top == -1)	return;
	top--;
}
char peek(){
	if(top == -1)	return;
	return stack[top];
}
int value(char c){
	if(c == '+'|| c == '-')	return 1;
	if(c == '*'|| c == '/')	return 2;
	if(c == '^')	return 3;
	else return 0;
}
void print_stack(){
	printf("Stack: ");
	for(int i = 0; i <= top; i++){
		printf("%c ", stack[i]);
	}
	printf("\n");
}

int main(){
	char str[max];
	scanf("%s", &str);
	char post[max];
	int j = 0;
	for(int i = 0; str[i] != '\0'; i++){
		
		printf("Processing: %c\n", str[i]);
		if((str[i] >= 'a'  && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')){
			post[j++] = str[i];
		}
		else if(str[i] == '('){
			push(str[i]);
		}
		else if(str[i] == ')'){
			while(peek() != '('){
				post[j++] = peek();
				pop();
			}
			pop();
		}
		else{
			while(value(str[i]) <= value(peek())){
				post[j++] = peek();
				pop();
			}
			push(str[i]);
		}
		print_stack();
	}
	while(top != -1){
		post[j++] = peek();
		pop();
	}
	print_stack();
	post[j++] = '\0';
	printf("\nPostfix expression: %s", post);
	
}

/*
Sample input: (a+b)*(c+d)
Sample Output: ab+cd+*


*/
