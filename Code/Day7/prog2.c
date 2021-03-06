#include<stdio.h>
#include<stdlib.h>

struct stack{
	int data;
	struct stack *next;
};

struct stack* push(struct stack *,int);
struct stack* pop(struct stack *);

void main()
{
	int ch,data;
	struct stack *top;
	printf("Enter\n1 to PUSH data\n2 to POP data\n0 to exit\n");
	while(1)
	{	
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter data:");
				scanf("%d",&data);
				top=push(top,data);
				printf("Element added\n");
				continue;
			case 2:
				data=top->data;
				top=pop(top);
				printf("Pop data: %d\n",data);
				continue;
			case 0:
				break;
			default:
				printf("Enter correct choice\n");
				continue;
		}
		break;
	}
}

struct stack* push(struct stack *top,int x)
{
	struct stack *temp;
	temp=(struct stack*)malloc(sizeof(struct stack));
	temp->data=x;
	temp->next=NULL;
	if(top==NULL)
	{      
		return temp;
	}
	temp->next=top;
	return temp;
}

struct stack* pop(struct stack *top)
{
	struct stack *temp;
	temp=top;
	if(top==NULL)
	{
		printf("Stack Underflow");
		return top;
	}
	else
	{
		top=top->next;
		temp->next=NULL;
		free(temp);
		return top;
	}
}
