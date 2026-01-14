#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int info;
	struct node *next;
};
struct node *create(struct node *);
struct node *insert(struct node *,int,int);
struct node *delet(struct  node *,int);
void display(struct node *);

main()
{
	struct node *lst=NULL;
	int ele,pos;
	char ch;
	clrscr();
	do
	{
		cout<<"\n\n\tOPTIONS\t\t\tChoice";
		cout<<"\n\t Create \t\t C/c";
		cout<<"\n\t Insert \t\t I/i";
		cout<<"\n\t Delete\t\t\t D/d";
		cout<<"\n\t Exit\t\t\t X/x";
		cout<<"\n\n Enter your choice:";
		do
			ch=getchar();
		while(strchr("CcIiDdXx",ch)==NULL);
		switch(ch)
		{
			case'C':
			case'c':lst=create(lst);
				cout<<"\n***LIST***";
				display(lst);
				break;

			case'I':
			case'i':cout<<"\nEnter information:";
				cin>>ele;
				cout<<"\nSelect Position of Insertion:";
				cin>>pos;
				lst=insert(lst,ele,pos);
				cout<<"\n***LIST***";
				display(lst);
				break;

			case'D':
			case'd':if(lst==NULL)
					cout<<"\nlistis empty";
				else
				{
					cout<<"\nEnter information to delete:";
					cin>>ele;
					lst=delet(lst,ele);
					if(lst==NULL)
						cout<<"\nThe list has become empty";
					else
					{
						cout<<"\n***LIST***";
						display(lst);
					}
				}
			}
		}while(ch!='X'&& ch!='x');
}

struct node *create(struct node*lst)
{
	struct node *newnode,*last;
	int ele;
	cout<<"\nEnter information:";
	cin>>ele;
	while(ele!=0)
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		newnode->info=ele;
		if(lst==NULL)
			lst=newnode;
		else
			last->next=newnode;
		last=newnode;
		last->next=lst;
		cout<<"\n Enter information:";
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
		temp=lst;
		while(temp->next!=lst)
			temp=temp->next;
		newnode->next=lst;
		lst=newnode;
		temp->next=lst;
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
		temp->next=newnode;
	}
	return lst;
}

struct node *delet(struct node *lst,int ele)
{
	struct node *temp,*prev;
	temp=lst;
	prev=NULL;
	while((temp->info !=ele)&&(prev->next!=lst))
	{
		prev=temp;
		temp=temp->next;
	}
	if(prev->next==lst)
		cout<<"\nThe information not present...";
	else
	{
		if(prev==NULL)
		{
			if(temp->next==lst)
				lst=NULL;

			else
			{
				prev=lst;
				while(prev->next!=lst)
				     prev=prev->next;
				lst=lst->next;
				prev->next=lst;
			}
		}
		else
			prev->next=temp->next;
		free(temp);
	}
	return lst;
}

void display(struct node *lst)
{
	struct node *temp;
	temp=lst;
	cout<<"\nLIST->";
	do
	{
		cout<<temp->info<<"->";
		temp=temp->next;
	}while(temp!=lst);
	cout<<"|";
}
