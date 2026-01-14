#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int info;
	struct node *next;

}       ;

void insert(int);
int delet();
void display();
struct node *front,*rear;

void main()
{
	int ele;
	char ch;
	front=rear=NULL;
	clrscr();
	do
	{
		cout<<"\n\tOptions\t\t\tChoice";
		cout<<"\n\tInsert\t\t\tI/i";
		cout<<"\n\tDelete\t\t\tD/d";
		cout<<"\n\tExit\t\t\tX/x";
		cout<<"\nEnter your choice : ";
		do
			ch=getchar();
		while(strchr("IiDdXx",ch)==NULL);
		switch(ch)
		{
			case'I':
			case'i':
				cout<<"\nEnter element : ";
				cin>>ele;
				insert(ele);
				cout<<"\n***** QUEUE *****";
				display();
				break;

			case'D':
			case'd':
				if(front==NULL)
				{
					cout<<"\nQueue is empty.";
				}
				else
				{
					ele=delet();
					cout<<"\nThe deleted element is : "<<ele;
					if(front==NULL)
						cout<<"\nThe queue has becomne empty.";
					else
					{
						cout<<"\n***** QUEUE *****";
						display();
					}
				}
		}
	}while(ch!='X' && ch!='x');
}

void insert(int ele)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=ele;
	if(rear==NULL)
		front=rear=newnode;
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
	rear->next=front;
}


int delet()
{
	int ele;
	struct node *temp1;
	temp1=front;
	ele=front->info;
	if(front==rear)
		front=rear=NULL;
	else
	{
		front=front->next;
		rear->next=front;
	}
	free(temp1);
	return ele;
}

void display()
{
	struct node *temp;
	cout<<"\nfront->";
	temp=front;
	do
	{
		cout<<temp->info<<"->";
		temp=temp->next;
	}while(temp!=front);
	cout<<"Rear";
}