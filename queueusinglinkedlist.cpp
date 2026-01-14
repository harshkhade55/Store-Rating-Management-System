#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int info;
	struct node *next;
};

struct node *front,*rear;
void insert(int);
int delet();
void display();


main()
{
	int ele;
	char ch;
	clrscr();
	do
	{
		cout<<"\n\tOptions\t\t\tChoice";
		cout<<"\n\tInsert\t\t\tI/i";
		cout<<"\n\tDelet\t\t\tD/d";
		cout<<"\n\tExit\t\t\tX/x";
		cout<<"\nEnter your choice : ";
		do
			ch=getchar();
		while(strchr("IiDdXx",ch)==NULL);
		switch(ch)
		{
			case'I' :
			case'i' :
				cout<<"\nEnter element : ";
				cin>>ele;
				insert(ele);
				cout<<"\n**** QUEUE ****";
				display();
				break;

			case'D' :
			case'd' :
				if(front==NULL)
					cout<<"\nQueue is empty." ;
				else
				{
					ele=delet();
					cout<<"\nThe deleted element is :"<<ele;
					if(front==NULL)
						cout<<"\nThe queue has become empty.";
					else
					{
						cout<<"\n**** QUEUE ****";
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
	newnode ->info=ele;
	newnode ->next=NULL;
	if(rear==NULL)
		front=rear=newnode;
	else
	{
		rear ->next=newnode;
		rear=newnode;
	}
}


int delet()
{
int ele;
struct node *temp;
temp=front;
ele=front ->info;
front=front ->next;
free(temp);
if(front==NULL)
	rear=NULL ;
return ele;
}

void display()
{
	struct node *temp;
	cout<<"\nFront->";
	for(temp=front;temp!=NULL;temp=temp->next)
		cout<<temp->info<<"->";
	cout<<"Rear";
}