#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void initialize();
void insert(int);
void delete(int);
void find(int);

struct node
{
	int data;
	struct node *next;
};
struct node *hash[MAX];

void main()
{
	int ch,data;
	initialize();
	printf("Enter\n1 to Insert\n2 to Delete\n3 to Find\n0 to Exit\n");
	while(1)
	{
		printf("Enter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter data to insert:");
				scanf("%d",&data);
				insert(data);
				continue;
			case 2:
				printf("Enter data to delete:");
				scanf("%d",&data);
				delete(data);
				continue;
			case 3:
				printf("Enter data to find:");
				scanf("%d",&data);
				find(data);
				continue;
			case 0:
				break;
			default:
				continue;
		}
		break;
	}
	
}

void initialize()
{
	int i;
	for(i=0;i<MAX;i++)
		hash[i]=NULL;
}


void insert(int data)
{
	int index;
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	index=data%MAX;
	temp->data=data;
	temp->next=hash[index];
	hash[index]=temp;
	printf("Data Added\n");
}

void delete(int data)
{
	int index;
	struct node *temp,*prev;
	index=data%MAX;
	temp=hash[index];
	if(temp==NULL)
	{
		printf("Hash node empty");
		return;
	}
	else if(temp->data==data)
	{
		hash[index]=temp->next;
		temp->next=NULL;
		free(temp);
		printf("Node deleted\n");
		return;
	}	
	else
	{
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
			if(temp->data==data)
			{
				prev->next=temp->next;
				temp->next=NULL;
				free(temp);
				printf("Node deleted\n");
				return;
			}
		}
	}
	printf("Data not found\n");	
}

void find(int data)
{
	int index,i=0;
	struct node *temp;
	index=data%MAX;
	temp=hash[index];
	if(temp->data==data)
	{
			printf("Data found at index: %d\nat position: %d\n",index,i);
			return;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
			i++;
			if(temp->data==data)
			{
				printf("Data found at index: %d\nat position: %d\n",index,i);
				return;
			}
		}
	}
	printf("Data not Found\n");
}
