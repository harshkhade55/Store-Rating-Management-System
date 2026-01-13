
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

int top=-1;
void push(char [],char);
char pop(char []);
void main()
{
	char expr[50],st[50],ele;
	int i;
	clrscr();
	cout<<"\nEnter expression : ";
	i=0;
	while((expr[i++]=getchar())!='\n');
	expr[-i]='\0';
	for(i=0;expr[i]!='\0';i++)
	{
		if(expr[i]=='('||expr[i]=='{'||expr[i]=='[')
			push(st,expr[i]);
		else
		{
			if(expr[i]==')'||expr[i]=='}'||expr[i]==']')
			{
				if(top==-1)
				{
					switch(expr[i])
					{
						case')':
							cout<<"\n ( reqired";
							break;

						case'}':
							cout<<"\n { reqired";
							break;
						case']':
							cout<<"\n [ reqired";
							break;
					}
				}
				else
				{
					ele=pop(st);
					switch(expr[i])
					{
						case')':
							if(ele=='{'||ele=='[')
								cout<<"\n ( reqired";
							break;
						case'}':
							if(ele=='('||ele=='[')
								cout<<"\n { reqired";
							break;
						case']':
							if(ele=='('||ele=='{')
								cout<<"\n [ reqired";
							break;
					}
				}
			}
		}
	}
	while(top>-1)
	{
		ele=pop(st);
		switch(ele)
		{
			case'(':
				cout<<"\n ) required";
				break;
			case'{':
				cout<<"\n } required";
				break;
			case'[':
				cout<<"\n ] required";
				break;
		}
	}
	getch();
}

void push(char st[50],char ele)
{
	st[++top]=ele;
}

char pop(char st[50])
{
	char ele;
	ele=st[top--];
	return ele;
}