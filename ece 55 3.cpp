#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void add_begin(int val);
void add_end(int val);
void add_before(int num,int val);
void add_after(int num,int val);
void display();
int main()
{ 
	int ch,a,num,val;
	printf("\n1.INSERT AT BEGIN\n2.INSERT AT END\n3.INSERT BEFORE A NODE\n4.INSERT AFTER A NODE\n5.DISPLAY\n6.EXIT\n");
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter a value : ");
				scanf("%d",&a);
				add_begin(a);
				display();
			break;
			case 2:
				printf("Enter a value : ");
				scanf("%d",&a);
				add_end(a);
				display();
			break;
			case 3:
				printf("Enter the number to add before : ");
				scanf("%d",&num);
				printf("Enter the value : ");
				scanf("%d",&val);
				add_before(num,val);
				display();
			break;
			 case 4:
			 	printf("Enter the number to add after : ");
				scanf("%d",&num);
				printf("Enter the value : ");
				scanf("%d",&val);
				add_after(num,val);
				display();
			 break;
			 case 5:
				exit(0);
			default:
				printf("Wrong choice....");	
		}
	}
	
	return 0;
}
void add_begin(int val)
{
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=val;
	new_node->next=start;
	start=new_node;
	
}
void add_end(int val)
{
	struct node *ptr;
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=val;
	new_node->next=NULL;
	if(start==NULL)
	{
		start=ptr;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=new_node;
	}
	
}
void add_before(int num,int val)
{
	struct node *preptr,*ptr;
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=val;
	new_node->next=NULL;
	ptr=start;
	preptr=ptr;
	while(ptr->data!=num)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=new_node;
	new_node->next=ptr;
}
void add_after(int num,int val)
{
	struct node *ptr;
	struct node *new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=val;
	new_node->next=NULL;
	ptr=start;
	while(ptr->data!=num)
	{
		ptr=ptr->next;
	}
	new_node->next=ptr->next;
	ptr->next=new_node;
}
void display()
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("List is empty");
	}
	else
	{
		ptr=start;
		while(ptr!=NULL)
		{
			printf("\t%d",ptr->data);
			ptr=ptr->next;
		}
	}	
}

