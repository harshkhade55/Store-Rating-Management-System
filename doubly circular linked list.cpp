#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
		int info;
		struct node *next,*prev;
};
struct node *create(struct node*);
struct node *insert(struct node *,int,int);
struct node *delet(struct node *,int);
void display(struct node *);
main()
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
		cout<<"\nEnter your choice:";
		do
			ch=getchar();
		while(strchr("CcIiDdXx",ch)==NULL);
		switch(ch)
		{
			case 'C':
			case 'c':
				lst=create(lst);
				cout<<"\nThe list is:";
				display(lst);
				break;
			case 'I':
			case 'i':
				cout<<"\nEnter information:";
				cin>>ele;
				cout<<"\nenter position of insertion:";
				cin>>pos;
				lst=insert(lst,ele,pos);
				cout<<"\nThe list is:";
				display(lst);
				break;
			case 'D':
			case 'd':
				if(lst==NULL)
					cout<<"\nThe list is empty";
				else
				{
					cout<<"\nEnter information to delete:";
					cin>>ele;
					lst=delet(lst,ele);
					if(lst==NULL)
						cout<<"\nThe list has become empty";
					else
					{
						cout<<"\nThe list is:";
						display(lst);
					}
				}
		}
	}while(ch!='X'&& ch!='x');
}

struct node *create(struct node *lst)
{
	struct node *newnode;
	int ele;
	cout<<"\nEnter information:";
	cin>>ele;
	while(ele!=0)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->info=ele;
		if(lst==NULL)
		{
			lst=newnode;
			lst->next=lst;
			lst->prev=lst;
		}
		else
		{
			newnode->prev=lst->prev;
			newnode->next=lst;
			lst->prev->next=newnode;
			lst->prev=newnode;
		}
		cout<<"\nEnter information:";
		cin>>ele;
	}
	return lst;
}

struct node *insert(struct node *lst,int ele,int pos)
{
	struct node *newnode,*temp;
	int p;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->info=ele;
	if(pos==1)
	{
		newnode->next=lst;
		newnode->prev=lst->prev;
		lst->prev->next=newnode;
		lst->prev=newnode;
		lst=newnode;
	}
	else
	{
		p=2;
		temp=lst;
		while((p!=pos)&&(temp->next!=lst))
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

struct node *delet(struct node *lst,int ele)
{
	struct node *temp1,*temp2;
	temp1=lst;
	temp2=NULL;
	while((temp1->info!=ele)&&(temp2->next!=lst))
	{
		temp2=temp1;
		temp1=temp1->next;
	}
	if(temp2->next==lst)
		cout<<"\nInformation is not present";
	else
	{
		if(temp2==NULL)
		{
			if(temp1->next==lst)
				lst=NULL;
			else
			{
				temp1->next->prev=temp1->prev;
				temp1->prev->next=temp1->next;
				lst=lst->next;
			}
		}
		else
		{
			temp1->next->prev=temp1->prev;
			temp1->prev->next=temp1->next;
		}
	}
	return lst;
}

void display(struct node *lst)
{
	struct node *temp1,*temp2;
	temp1=lst;
	temp2=NULL;
	cout<<"\nThe list in forward direction->";
	do
	{
		cout<<temp1->info<<"->";
		temp2=temp1;
		temp1=temp1->next;
	}while(temp1!=lst);
	cout<<"\nThe list in backward direction->";
	do
	{
		cout<<temp2->info<<"->";
		temp2=temp2->prev;
	}while(temp2!=lst->prev);
}