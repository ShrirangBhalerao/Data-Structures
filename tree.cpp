#include<iostream>
#include<stdlib.h>
using namespace std;


class Tree_Node
{
public: 
	int data;
	Tree_Node *left,*right;                       
	Tree_Node()
	{
		left=NULL;
		right=NULL;
	}
};

class Tree 
{
public:
	Tree_Node *head,*temp,*first,*one;
	Tree()
	{
		head=NULL;
		first=head;
		one = first;
	}

	Tree_Node * create()
	{

		temp=new Tree_Node;
		cout<<"\n\n\tENTER DATA :  ";
		cin>>temp->data;
		if(first==NULL)
		{
			first=temp;
			head=temp;
		}
		else
		{
			while(1)
			{
				int a,b;
				cout<<"\n\tWHERE WOULD U LIKE TO INSERT THE DATA : ";
				cout<<"\n\t\t1.LEFT OF  "<<head->data;
				cout<<"\n\t\t2.RIGHT OF "<<head->data;
				cout<<"\n\t\t3.NONE ";
				cout<<"\n\tENTER YOUR CHOICE : ";
				cin>>a;
				if(a==1)
				{	
					if(head->left==NULL)
					{
						head->left=temp;
						break;
					}
					else
					{
						cout<<"\n\tOCCUPIED\n\t";
					}
				}
				else
				{
					if(a==2)
					{	
						if(head->right==NULL)
						{
							head->right=temp;
							break;
						}
						else
						{
							cout<<"\n\tOCCUPIED\t";
						}
					}

					else
					{
						if(a==3)
						{
							b:
						cout<<"\n\tWHERE WOULD U LIKE TO TRAVERSE : ";
							cout<<"\n\t\t1.LEFT OF  "<<head->data;
							cout<<"\n\t\t2.RIGHT OF "<<head->data;
							cout<<"\n\t\t3.NONE ";
							cout<<"\n\tENTER YOUR CHOICE : ";
							cin>>a;
							if(a==1)
								head=head->left;
							if(a==2)
								head=head->right;
							if(a==3)
							{
								head=first;
								goto b;
							}
							
								
						}
				
					}
				}
			}			

		}
		return first;
	}

	Tree_Node * copy(Tree_Node *first)
	{
		Tree_Node *p=NULL;
		if(first!=NULL)
		{
			p=new Tree_Node;
			p->data=first->data;
			p->left=copy(first->left);
			p->right=copy(first->right);
		}
		return p;	
	}
};

class stack_node
{
public:
	stack_node *next;
	Tree_Node *curr;

	stack_node()
	{
		next=NULL;}
};

class stack
{
public:
	stack_node *sp,*temp;

	stack()
	{
		sp=NULL;}

	void push(Tree_Node *p)
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
		Tree_Node *l;
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

class display
{
public:
	stack s;
	int a,b;
	
	
	
	
	void inorder(Tree_Node *first)
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
			cout<<first->data<<"  ";
			first=first->right;
			while(first!=NULL)
			{
				s.push(first);
				first=first->left;
			}
		}			
	}	
	
	void preorder(Tree_Node *first)
	{
		cout<<"\n\tPRE-ORDER TREE TRAVERSAL :    ";
		while(first!=NULL)
		{
			cout<<first->data<<"  ";
			s.push(first);
			first=first->left;
		}
		while(!s.empty())
		{
			first=s.pop();
			first=first->right;
			while(first!=NULL)
			{
				cout<<first->data<<"  ";
				s.push(first);
				first=first->left;
			}					
		}
	}	
	
	void postorder(Tree_Node *first)
	{
		if(first!=NULL)
		{
			postorder(first->left);
			postorder(first->right);
			cout<<first->data<<"  ";
		}
	}		
			
		
	
	void leaf_node(Tree_Node *first)
	{
		if(first!=NULL)
		{
			leaf_node(first->left);
			leaf_node(first->right);
			if(first->left==NULL && first->right==NULL)
			cout<<"\t"<<first->data;
		}
	}
	
	int max(int w1,int w2)
	{
		if(w1>w2)
		return w1;
		return w2;
	}			
	
	int depth(Tree_Node *first)
	{
		if(first==NULL)
			return 0;
		return 1+max(depth(first->left),depth(first->right));
	}
	
	void traversal(Tree_Node *first)
	{
		int ch;
		cout<<"\n\n\tMODES OF TREE TRAVERSAL";
		cout<<"\n\n\t\t1.IN-ORDER";
		cout<<"\n\n\t\t2.PRE-ORDER";
		cout<<"\n\n\t\t3.POST-ORDER";
		cout<<"\n\n\tENTER YOUR CHOICE :   ";
		cin>>ch;
		switch(ch)
		{
			case 1: inorder(first);
				break;
			case 2: preorder(first);
				break;
			case 3: cout<<"\n\tPOST-ORDER TREE TRAVERSAL :  "; 
				postorder(first);
				break;
			default: cout<<"\n\n\tINVALID CHOICE ";
			break;
		}		
	
	
	}
	
};						
		




int main()
{
	int b=1,ch,c;
	Tree_Node *one, *two;
	Tree t;
	int a=1;
	display d;
	cout<<"\nTHIS PROGRAM FEATURES THE IMPLEMENTATION OF BINARY TREE \n";
	do
	{
		cout<<"\n\n\tLIST OF OPERATIONS";
		cout<<"\n\n\t\t 1.CREATION OF TREE";
		cout<<"\n\n\t\t 2.TREE TRAVERSAL";
		cout<<"\n\n\t\t 3.DEPTH OF TREE";
		cout<<"\n\n\t\t 4.LEAF NODES OF TREE";		
		cout<<"\n\n\t\t 5.COPYING A TREE";
		cout<<"\n\n\t\t 6.EXIT";
		cout<<"\n\n\tENTER YOUR CHOICE :   ";
		cin>>ch;
		switch(ch)
		{
			case 1 : 		
				while(a==1)
				{
					one = t.create();
					two=one;
					cout<<"\n\t\tCONTINUE ?  (1/0)  ";
					cin>>a;
				}
				if(a!=1)
					cout<<"\n\n\t\tERROR: TREE IS ALREADY CREATED\n";
						break;
				
			case 2 :if(a!=1){ d.traversal(one);}
				else cout<<"\n\n\t\tERROR: TREE IS NOT CREATED\n";
					break;
			case 3: 
				if(a!=1){ c=d.depth(one);
				cout<<"\n\tDEPTH OF TREE  IS :  "<<c;}
				else cout<<"\n\n\t\tERROR: TREE IS NOT CREATED\n";	
					break;
				
			case 4 :if(a!=1){cout<<"\n\t LEAF NODES OF TREE :  ";
				d.leaf_node(one);}
				else cout<<"\n\n\t\tERROR: TREE IS NOT CREATED\n"; 
				 	break;
			case 5:if(a!=1){cout<<"\n\t TREE HAS BEEN SUCCESSFULLY COPIED ";
				two=t.copy(one);}
				else cout<<"\n\n\t\tERROR: TREE IS NOT CREATED\n"; 
					break;
			
						
			case 6 :cout<<"\n\n\t\t\tTHANK-YOU!!!";
					break;	

		}
	}while(ch!=6);
}		






