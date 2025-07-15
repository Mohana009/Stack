#include<stdio.h>
int stack[1000];
int top = -1;
void push(int val){
	if(top == 1000 - 1){
		printf("Stack is filled\n");
	}
	else{
		stack[++top] = val;
	}
}
void pop(){
	if(top == -1){
		printf("Stack is empty\n");
	}
	else{
		top--;
	}
}
void isEmpty(){
	if(top == -1)	printf("Stack is empty\n");
	else printf("Stack is not empty\n");
}
void isFull(){
	if(top == 1000 - 1)	printf("Stack is full\n");
	else	printf("Stack is not full\n");
}
int Top(){
	if(top == -1){
		printf("Stack is empty\n");
	}
	else{
		int res = stack[top];
		return res;
	}
}
int Size(){
	return top + 1;
}
void Display(){
	int temp = top;
	if(temp == -1){
		printf("Stack is empty\n");
	}
	else{
		while(temp != -1){
			printf("%d ", stack[temp]);
			temp--;
		}
	}
}
int Max(){
	int temp = top;
	int max = stack[temp];
	while(temp >= 0){
		if(max <= stack[temp]){
			max = stack[temp];
		}
		temp--;
	}
	return max;
}
int main(){
	int n;
	printf("No.of elements: ");
	scanf("%d", &n);
	int val;
	printf("Enter elements: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &val);
		push(val);
	}
	Display();
	printf("\n");
	int choice;
	while(1){
		printf("\nClick 1 to push an element in to stack\n");
		printf("Click 2 to pop element from stack\n");
		printf("Click 3 to get top element from stack\n");
		printf("Click 4 to check if the stack is empty\n");
		printf("Click 5 to check if the stack is full\n");
		printf("Click 6 to check the size of stack\n");
		printf("Click 7 to get the maximum element from stack\n");
		printf("Click 0 to exit\n\n");
	  
    scanf("%d", &choice);
		if(choice == 1){
			printf("Enter element to push: ");
			scanf("%d", &val);
			push(val);
			printf("\nNow the stack is: ");
			Display();
			printf("\n");
		}
		else if(choice == 2){
			pop();
			printf("\nNow the stack is: ");
			Display();
			printf("\n");
		}
		else if(choice == 3){
			printf("\nTop element is: %d\n", Top());
		}
		else if(choice == 4){
			isEmpty();
		}
		else if(choice == 5){
			isFull();
		}
		else if(choice == 6){
			printf("\nSize of stack is: %d\n",Size());
		}
		else if(choice == 7){
			printf("\nMaximum element is: %d\n", Max());
		}
		else if(choice == 0){
			break;
		}
		else{
			printf("\nEnter valid value\n");
		}
	
	}
}
