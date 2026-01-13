#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *next;
};

struct node *push(struct node *,int);
struct node *pop(struct node *);
void display(struct node *);

void main()
{
	struct node *top=NULL;
	int ele;
	char ch;
	clrscr();
	do
	{
		cout<<"\n\tOptions\t\t\t\tChoice";
		cout<<"\n\tPush\t\t\t\tP/p";
		cout<<"\n\tPop\t\t\t\tO/o";
		cout<<"\n\tExit\t\t\t\tX/x";
		cout<<"\nEnter your choice : ";
		do
			ch=getchar();
		while(strchr("PpOoXx",ch)==NULL);
		switch(ch)
		{
			case'P':
			case'p':


					cout<<"\nEnter element : ";
					cin>>ele;
					top=push(top,ele);
					cout<<"\n***** STACK *****";
					display(top);


				break;

			case'O':
			case'o':
				if(top==NULL)
				{
					cout<<"\nstack is empty.";
				}
				else
				{
					top=pop(top);
					display(top);
					if(top==NULL)
						cout<<"\nStack has become empty.";
				}

		}
	}while(ch!='X' && ch!='x');
}

struct node *push(struct node *top,int ele)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=ele;
	newnode->next=top;
	top=newnode;
	return top;
}

struct node *pop(struct node *top)
{
	struct node *temp;
	temp=top;
	cout<<"\nPopped element is : "<<top->info;
	top=top->next;
	free(temp);
	return(top);
}
void display(struct node *top)
{
	struct node *temp;
	cout<<"\nTop-->";
	for(temp=top;temp!=NULL;temp=temp->next)
		cout<<temp->info<<"-->";
	cout<<"|";
}