#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;



class Tree_Node
{
public: 
	char data;
	int flag;
	Tree_Node *left,*right;                       
	Tree_Node()
	{
		left=NULL;
		right=NULL;
	}
};

class stack_node
{
public:
	stack_node *next;
	Tree_Node *curr;
	
	stack_node()
	{
		next=NULL;
	}
};

class stack
{
public:
	stack_node *sp,*temp;
	stack()
	{
		sp=NULL;
	}

	void push(Tree_Node *p )
	{
		temp=new stack_node;
		temp->curr=p;
		if(sp==NULL)
		{
			sp=temp;
		}
		else
		{
			temp->next=sp;
			sp=temp;
		}
	}

	Tree_Node * pop()
	{
		Tree_Node * l;
		l=sp->curr;
		sp=sp->next;
		return l;
	}
	
	int empty()
	{
		if(sp==NULL)
			return 1;
		return 0;	

	}
};

class Tree
{
public:
	 Tree_Node *head,*temp,*first,*root;

	Tree_Node * post_order()
	{
		char a[30],b;
		stack s;
		int i=0;
		while(1)
		{
			cout<<"\n\n\tENTER POST-FIX EXPRESSION :  ";
			cin>>a;
			
			if(!isalnum(a[i]))
			{
				cout<<"\n\tERROR:INVALID POSTFIX RXPRESSION";
			}	
			else
				break;
		}
			
		while(a[i]!='\0')
		{
			b=a[i];
			temp=new Tree_Node;
			temp->data=b;
			i++;

			if(isalnum(b))
			{
				s.push(temp);
			}
			else
			{
				head=s.pop();
				first=s.pop();
				temp->left=first;
				temp->right=head;
				s.push(temp);
			}
		}
		root=s.pop();
		return root;
	}


	Tree_Node * pre_order()
	{
		char a[30],b;
		stack s;
		int i;
		while(1)
		{
			cout<<"\n\n\tENTER PRE-FIX EXPRESSION :  ";
			cin>>a;
			
			i=strlen(a)-1;
			if(!isalnum(a[i]))
			{
				cout<<"\n\tERROR:INVALID PREFIX RXPRESSION";
			}	
			else
				break;
		}
		
		while(i!=-1)
		{
			b=a[i];
			temp=new Tree_Node;
			temp->data=b;
			i--;
			if(isalnum(b))
			{
				s.push(temp);
			}
			else
			{
				head=s.pop();
				first=s.pop();
				temp->left=head;
				temp->right=first;
				s.push(temp);
			}
		}
		root=s.pop();
		return root;
	}
};


class iterative_display
{
public:

	stack s;
	
	void preorder_i(Tree_Node *first)
	{
		cout<<"\n\tPRE-ORDER TREE TRAVERSAL :    ";
		while(first!=NULL)
		{
			cout<<first->data;
			s.push(first);
			first=first->left;
		}
		while(!s.empty())
		{
			first=s.pop();
			first=first->right;
			while(first!=NULL)
			{
				cout<<first->data;
				s.push(first);
				first=first->left;
			}					
		}
		cout<<"\n";
	}	
	
	
	void inorder_i(Tree_Node *first)
	{
		cout<<"\n\tIN-ORDER TREE TRAVERSAL :    ";
		while(first!=NULL)
		{
			s.push(first);
			first=first->left;
		}					
		while(s.empty()==0)
		{
			first=s.pop();
			cout<<first->data;
			first=first->right;
			while(first!=NULL)
			{
				s.push(first);
				first=first->left;
			}
		}
		cout<<"\n";			
	}
	
	void postorder_i(Tree_Node *first)
	{
		cout<<"\n\tPOST-ORDER TREE TRAVERSAL :    ";
		while(first!=NULL)
		{
			first->flag=0;
			s.push(first);
			first=first->left;
		}
		while(!s.empty())
		{
			first=s.pop();
			if(first->flag==0)
			{
				first->flag=1;
				s.push(first);
				first=first->right;
				while(first!=NULL)
				{
					first->flag=0;
					s.push(first);
					first=first->left;
				}
			}
			else
				cout<<first->data;
		}
	}					
			
	
	
		
};
	


class recurssive_display
{
public:

	void inorder_r(Tree_Node *root)
	{
		if(root!=NULL)
		{
			inorder_r(root->left);
			cout<<root->data;
			inorder_r(root->right);
		}
	}

	void postorder_r(Tree_Node *root)
	{
		if(root!=NULL)
		{
			postorder_r(root->left);
			postorder_r(root->right);
			cout<<root->data;
		}
	}

	void preorder_r(Tree_Node *root)
	{
		if(root!=NULL)
		{
			cout<<root->data;
			preorder_r(root->left);
			preorder_r(root->right);
		}
	}

};


int main()
{
	int ch,ch1;
	Tree t;
	Tree_Node *root=NULL;
	recurssive_display r;
	iterative_display i;
	cout<<"\n\tTHIS PROGRAM ILLUSTRATES IMPLIMENTATION ON EXPRESSION TREE\n";
	do
	{
		
		cout<<"\n\n\tLIST OF OPERATIONS\n";
		cout<<"\n\t\t1.CREATION OF EXPRESSION TREE\n ";
		cout<<"\n\t\t2.PRE-ORDER TREE TRAVERSAL\n ";
		cout<<"\n\t\t3.IN-ORDER TREE TRAVERSAL\n ";
		cout<<"\n\t\t4.POST-ORDER TREE TRAVERSAL\n ";
		cout<<"\n\t\t5.EXIT \n";
		cout<<"\n\n\tENTER YOUR CHOICE :   ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n\tWHICH FORM OF EXPRESSION WOULD YOU LIKE TO ENTER";
				cout<<"\n\n\t\t1.POST-FIX";
				cout<<"\n\n\t\t2.PRE-FIX";
				cout<<"\n\n\tENTER YOUR CHOICE :   ";
				cin>>ch1;
				switch(ch1)
				{
					case 1: root=t.post_order();
					break;
					case 2: root=t.pre_order();
					break;
				}
			break;

			case 2:
				if(root==NULL)
					 cout<<"\n\t\tERROR : TREE NOT CREATED ";
				else{	 
				cout<<"\n\tWHICH MODE OF IMPLEMENTATION IS EXPECTED :  ";
				cout<<"\n\n\t\t1.RECURSIVE";
				cout<<"\n\n\t\t2.ITERATIVE";
				cout<<"\n\n\tENTER YOUR CHOICE :   ";
				cin>>ch1;
				switch(ch1)
				{
					case 1: cout<<"\n\tPRE-ORDER TREE TRAVERSAL :    ";
						r.preorder_r(root);
					break;
					case 2: i.preorder_i(root);
					break;
				}}
			break;
			

			case 3:
				if(root==NULL)
					 cout<<"\n\t\tERROR : TREE NOT CREATED ";
				else{
				cout<<"\n\tWHICH MODE OF IMPLEMENTATION IS EXPECTED :  ";
				cout<<"\n\n\t\t1.RECURSIVE";
				cout<<"\n\n\t\t2.ITERATIVE";
				cout<<"\n\n\tENTER YOUR CHOICE :   ";
				cin>>ch1;
				switch(ch1)
				{
					case 1: cout<<"\n\tIN-ORDER TREE TRAVERSAL :    ";
						r.inorder_r(root);
					break;
					case 2: i.inorder_i(root);
					break;
				}}		
			break;
			
			case 4:
				if(root==NULL)
					 cout<<"\n\t\tERROR : TREE NOT CREATED ";
				else{
				cout<<"\n\tWHICH MODE OF IMPLEMENTATION IS EXPECTED :  ";
				cout<<"\n\n\t\t1.RECURSIVE";
				cout<<"\n\n\t\t2.ITERATIVE";
				cout<<"\n\n\tENTER YOUR CHOICE :   ";
				cin>>ch1;
				switch(ch1)
				{
					case 1: cout<<"\n\tPOST-ORDER TREE TRAVERSAL :    ";
						r.postorder_r(root);
					break;
					case 2: i.postorder_i(root);
					break;
				}}		
			break;
			
			case 5: cout<<"\n\n\t\t\tTHANK-YOU!!!";
			break;

		}
	}while(ch!=5);
}



