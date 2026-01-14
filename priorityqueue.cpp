#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insert(int,int);
int delet();
void display();
struct node
{
	int info,prio;
	struct node *next;
};

struct node *front,*rear;
void main()
{
int ele,p;
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
			cout<<"\nEnter information : ";
			cin>>ele;
			cout<<"\nEnter priority : ";
			cin>>p;
			insert(ele,p);
			cout<<"\n***** QUEUE *****";
			display();
			break;

		case'D':
		case'd':
			if(front==NULL)
				cout<<"\nQueue is empty.";
			else
			{
				ele=delet();
				cout<<"\nThe deleted information is : "<<ele;
				if(front==NULL)
					cout<<"\nThe queue has become empty.";
				else
				{
					cout<<"\n***** QUEUE *****";
					display();
				}
			}
	}

}while(ch!='X' && ch!='x');
}

void insert(int ele,int p)
{
	struct node *newnode,*temp,*prev;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=ele;
	newnode->prio=p;
	newnode->next=NULL;
	if(rear==NULL)
		front=rear=newnode;
	else
	{
		temp=front;
		prev=NULL;
		while((temp->prio>=p)&&(temp!=NULL))
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp==NULL)
		{
			rear->next=newnode;
			rear=newnode;
		}
		else
		{
			if(prev==NULL)
			{
				newnode->next=front;
				front=newnode;
			}
			else
			{
				newnode->next=temp;
				prev->next=newnode;
			}
		}
	}
}

int delet()
{
	int ele;
	struct node *temp;
	temp=front;
	ele=front->info;
	front=front->next;
	free(temp);
	if(front==NULL)
		rear=NULL;

	return ele;
}

void display()
{
	struct node *temp;
	cout<<"\nfront->";
	for(temp=front;temp!=NULL;temp=temp->next)
		cout<<temp->info<<"|"<<temp->prio<<"->";
	cout<<"Rear";
}