#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
} ;

struct node *front,*rear;
void insert(int);
int delet();
void display();

void main()
{
	int ele;
	char ch;
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
				cout<<"\nEnter Element : ";
				cin>>ele;
				insert(ele);
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
					cout<<"\nThe deleted element is : "<<ele;
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

void insert(int ele)
{
	struct node *newnode;
	char frend;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=ele;
	newnode->next=NULL;
	if(rear==NULL)
		front=rear=newnode;
	else
	{
		cout<<"\nSelect (f)ront/(R)ear : ";
		do
			frend=getchar();
		while(strchr("FfRr",frend)==NULL);
		switch(frend)
		{
			case'F':
			case'f':
				newnode->next=front;
				front=newnode;
				break;
			case'R':
			case'r':
				rear->next=newnode;
				rear=newnode;
		}
	}
}

int delet()
{
	struct node *temp1,*temp2;
	int ele;
	char frend;
	temp1=front;
	if(front->next==NULL)
	{
		ele=front->info;
		front=rear=NULL;
	}
	else
	{
		cout<<"\nSelect (F)ront/(R)ear : ";
		do
			frend=getchar();
		while(strchr("FfRr",frend)==NULL);
		switch(frend)
		{
			case'F':
			case'f':
				ele=front->info;
				front=front->next;
				break;
			case'R':
			case'r':
				temp2=front;
				while(temp2->next!=rear)
					temp2=temp2->next;
				ele=rear->info;
				temp1=rear;
				temp2->next=NULL;
				rear=temp2;
		}
		free(temp1);
		return(ele);
	}
}

void display()
{
	struct node *temp;
	cout<<"\nfront->";
	for(temp=front;temp!=NULL;temp=temp->next)
		cout<<temp->info<<"->";
	cout<<"Rear";
}