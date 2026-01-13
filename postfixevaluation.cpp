#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

int top=-1;
void push(char[],char);
char pop(char []);


void main()
{
	char expr[50],postfix[50],st[50],ele;
	int i,j;
	clrscr();
	cout<<"\nEnter Infix Expression : " ;
	i=0;
	while((expr[i++]=getchar())!='\n');
	expr[--i]='\0' ;

	for
	(i=0,j=0;expr[i]!='\0';i++)

	{
		if(expr[i]=='(')
			push(st,expr[i]);
		else
		{
			if(expr[i]==')')
			{
				ele=pop(st);
				while(ele!='(')
				{
					postfix[j++]=ele;
					ele=pop(st);
				}
			}
			else
			{
				if((expr[i]=='+')||(expr[i]=='-')||(expr[i]=='*')||(expr[i]=='/'))
				{
					if(top==-1)
						push(st,expr[i]) ;
					else
					{
						ele=pop(st);
						switch(ele)
						{
							case'*':
							case'/':
								if((expr[i]=='+')||(expr[i]=='-'))
								{
									postfix[j++]=ele;
									push(st,expr[i]);
								}
								else
								{
									push(st,ele);
									push(st,expr[i]);
								}
								break;
							default:
								push(st,ele);
								push(st,expr[i]);
						}
					}
				}
				else
					postfix[j++]=expr[i];
			}
		}
	}
	while(top>-1)
		postfix[j++]=pop(st);
	postfix[j]='\0';
	cout<<"\nThe postfix expression is : "<<postfix;
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
