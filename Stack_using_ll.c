#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
};
struct node *top = NULL;
struct node* Create_node(int val){
	struct node *nn = (struct node*)malloc(sizeof(struct node));
	nn->data = val;
	nn->prev = NULL;
	return nn;
}
void push(int val){
	struct node *nn = Create_node(val);
	if(top == NULL){
		top = nn;
	}
	else{
		nn->prev = top;
		top = nn;
	}
}
void pop(){
	if(top == NULL)	return;
	else	top = top->prev;
}
void Display(){
	struct node *temp = top;
	while(temp){
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}
int main(){
	int n;
	printf("Enter no.of nodes: ");
	scanf("%d", &n);
	int val;
	for(int i = 0; i < n; i++){
		scanf("%d", &val);
		push(val);
	}
	Display();
	pop();
	Display();
	push(6);
	Display();
}