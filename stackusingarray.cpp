#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

int top=-1;
void push(int[],int);
int pop(int[]);
void display(int[]);

void main()
{
	int st[10],ele;
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
				if(top<9)
				{
					cout<<"\nEnter element : ";
					cin>>ele;
					push(st,ele);
					cout<<"\n***** STACK *****";
					display(st);
				}
				else
					cout<<"\nStack is full";
				break;

			case'O':
			case'o':
				if(top==-1)
					cout<<"\nStack is empty.";
				else
				{
					ele=pop(st);
					cout<<"\nPopped element is : "<<ele;
					if(top==-1)
						cout<<"\nStack has become empty." ;
					else
					{
						cout<<"\n***** STACK *****";
						display(st);
					}
				}

		}
	}while(ch!='X' && ch!='x');
}

void push(int st[10],int ele)
{
	st[++top]=ele;
}

int pop(int st[10])
{
	int ele;
	ele=st[top--];
	return ele;
}

void display(int st[10])
{
	int i;
	cout<<"\nTop -->";
	for(i=top;i>-1;i--)
		cout<<st[i]<<"-->";
	cout<<"|";
}