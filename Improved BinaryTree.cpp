// Improved BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <set>



using namespace std;


class Node 
{
	public:
	int data;
	Node* right;
	Node* left;




	Node(int dat,Node* lef=NULL,Node* righ=NULL):data(dat),right(righ),left(lef)
	{

	};
	void push(int a)
	{
		if(a<data)
		{
			if(left==NULL)
			left=new Node(a);
			else
				left->push(a);
		}
		else
			if(right==NULL)
			right=new Node(a);
			else
				right->push(a);
	}

};

int Height(Node& root)
{
	int left=0;
	int right=0;
	if(root.left!=0)
	{
		left=1+Height(*root.left);
	}
	if(root.right!=0)
	{
		right=1+Height(*root.right);
	}
	return left<right?right:left;

}


int Sum(Node** root)
{
	int sum=0;
	if((*root)->left!=0)
	{
		sum+=1+Sum(&(*root)->left);
	}
	if((*root)->right!=0)
	{
		sum+=1+Sum(&(*root)->right);
	}
	return sum;
}


void Show(Node& root , int i=35)

{	
	
		cout<<setw(i)<<root.data<<endl;
		if(root.right != NULL)
		{
			cout<<endl;
			Show(*root.right ,i+5);
		}
		if(root.left != NULL)
		{
			Show(*root.left ,i-5);
		}
	
};



int _tmain(int argc, _TCHAR* argv[])
{

	
	
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int a;
	cout<<"Root value : ";
	cin>>a;
	Node *root = new Node(a);
	
	while(true)
	{
		system("CLS");
		SetConsoleTextAttribute(hConsole,4);
		Show(*root);
		cout<<endl;
		SetConsoleTextAttribute(hConsole,5);
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<"Binary tree height : "<<Height(*root)<<endl;
		cout<<"Binary tree sum : "<<Sum(&root)<<endl;
		int i;
		cout<<"Add new value : ";
		cin>>i;
		cout<<endl;
		root->push(i);
		

	}
	
	getchar();
	return 0;
}

