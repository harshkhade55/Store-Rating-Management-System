#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *left , *right;
	};
struct node *buildtree(struct node *,int);
void display(struct node *,int);
void preorder(struct node*);
void inorder(struct node *);
void postorder(struct node *);

main()
{
	struct node *root=NULL;
	int ele,l;
	clrscr();
	while(1)
	{
		cout<<"\nEnter information:";
		cin>>ele;
		if(ele==0)
			break;
		root=buildtree(root,ele);
		cout<<"\nThe tree is:\n";
		l=0;
		display(root,l);
	}
	cout<<"\nThe preoder traversal is:";
	preorder(root);
	cout<<"\n The inorder traversal is:";
	inorder(root);
	cout<<"\n The postorder traversal is:";
	postorder(root);
	getch();
}
struct node *buildtree(struct node *root,int ele)
{
	if(root==NULL)
	{	root=(struct node *)malloc(sizeof(struct node));
		root->left=NULL;
		root->info=ele;
		root->right=NULL;
		return root;
	}
	if(ele<root->info)
		root->left=buildtree(root->left,ele);
	else
	{
		if(ele>root->info)
			root->right=buildtree(root->right,ele);
	}
	return root;
}
void display(struct node *root,int l)
{
	int i;
	if(root!=NULL)
	{
		display(root->right,l+1);
		cout<<"\n";
		for(i=0;i<=l;i++)
			cout<<"     ";
		cout<<root->info<<"("<<l<<")";
		display(root->left,l+1);
	}
}

void preorder(struct node *root)
{
	if(root!=NULL)
	{
		cout<<root->info<<",";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->info<<",";
	}
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->info<<",";
		inorder(root->right);
	}
}

