
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *prev,*next;
};

struct node * create(struct node *);
struct node * insert(struct node *,int,int);
struct node * delet(struct node *,int);
void display(struct node *);

void main()
{
	struct node *lst=NULL;
	int ele,pos;
	char ch;
	clrscr();
	do
	{
		cout<<"\n\tOptions\t\t\tChoice";
		cout<<"\n\tCreate\t\t\tC/c";
		cout<<"\n\tInsert\t\t\tI/i";
		cout<<"\n\tDelete\t\t\tD/d";
		cout<<"\n\tExit\t\t\tX/x";
		cout<<"\nEnter your choice : ";
		do
			ch=getchar();
		while(strchr("CcIiDdXx",ch)==NULL);
		switch(ch)
		{
			case 'C':
			case 'c':
				lst=create(lst);
				cout<<"\n**** LIST ****";
				display(lst);
				break;
			case 'I':
			case 'i':
				cout<<"\nEnter information : ";
				cin>>ele;
				cout<<"\nEnter position of insertion : ";
				cin>>pos;
				lst=insert(lst,ele,pos);
				cout<<"\n**** LIST ****";
				display(lst);
				break;
			case 'D':
			case 'd':
				if(lst==NULL)
					cout<<"\nThe list is empty.";
				else
				{
					cout<<"\nEnter information to delete : ";
					cin>>ele;
					lst=delet(lst,ele);
					if(lst==NULL)
						cout<<"\nThe list has become empty.";
					else
					{
						cout<<"\n**** LIST ****";
						display(lst);
					}
				}

		}
	}while(ch!='X' && ch!='x');
}

struct node * create(struct node *lst)
{
	struct node *newnode,*last;
	int ele;
	cout<<"\nEnter information : ";
	cin>>ele;
	while(ele!=0)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->prev=NULL;
		newnode->info=ele;
		newnode->next=NULL;
		if(lst==NULL)
			lst=newnode;
		else
		{
			newnode->prev=last;
			last->next=newnode;
		}
		last=newnode;
		cout<<"\nEnter information : ";
		cin>>ele;

	}
	return lst;
}

struct node * insert(struct node *lst,int ele,int pos)
{
	struct node *newnode,*temp;
	int p;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->prev=NULL;
	newnode->next=NULL;
	newnode->info=ele;
	if(pos==1)
	{
		newnode->next=lst;
		lst->prev=newnode;
		lst=newnode;

	}
	else
	{
		p=2;
		temp=lst;
		while((p!=pos) && (temp->next!=NULL))
		{
			p++;
			temp=temp->next;
		}
		newnode->next=temp->next;
		newnode->prev=temp;
		temp->next->prev=newnode;
		temp->next=newnode;
	}
	return lst;
}

struct node * delet(struct node *lst,int ele)
{
	struct node *temp;
	temp=lst;
	while((temp->info!=ele) && (temp!=NULL))
		temp=temp->next;
	if(temp==NULL)
		cout<<"\nThe information not present.";
	else
	{
		if(temp==lst)
		{
			if(temp->next==NULL)
				lst=NULL;
			else
			{
				lst->next->prev=NULL;
				lst=lst->next;
			}

		}
		else
		{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
		}
		free(temp);
	}
	return lst;
}

void display(struct node *lst)
{
	struct node *temp1,*temp2;
	cout<<"\nList in forword direction->";
	temp1=lst;
	temp2=NULL;
	while(temp1!=NULL)
	{
		cout<<temp1->info<<"->";
		temp2=temp1;
		temp1=temp1->next;
	}
	cout<<"|\nList in backword direction->";
	while(temp2!=NULL)
	{
		cout<<temp2->info<<"->";
		temp2=temp2->prev;

	}
	cout<<"|";
}