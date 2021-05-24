#include<iostream>
using namespace std;


class Tree_node
{
public:
	float no;
	Tree_node  *left,*right;                    //tree node....
	Tree_node()
	{
		left=NULL;
		right=NULL;
	}
};


class node
{
public:
	Tree_node  *curr;             //node for queue...
	node * next;
};

class queue
{
private:
	node *sp ,*qp,*temp;
public:
	queue()
	{
		sp=NULL;
		qp=NULL;
	}

	void nqueue(Tree_node  *a)
	{
		temp=new node;
		temp->curr=a;
		if(sp==NULL)
		{                                         //nqueue function...
			sp=temp;
			qp=temp;
		}	
		else
		{
			qp->next=temp;
			qp=temp;
		}
	}

	Tree_node  * dqueue()
	{
	
			Tree_node  * a=sp->curr;           //dqueue function...
			sp=sp->next;
			return a;
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
private:
	Tree_node *head,*first,*temp;
	queue q;
	Tree_node * s[30];
	int i=0;
public:
	Tree()
	{
		head=NULL;
		first=head;
	}

	Tree_node * create()                    //creation  of binary search tree....
	{
		temp=new Tree_node ;
		cout<<"\n\t\tENTER NUMBER :  ";
		cin>>temp->no;
		if(head==NULL)
		{
			head=temp;
			first=head;
		}
		else
		{
			while(1)
			{
				if(temp->no > head->no  )
				{
					if(head->right==NULL)
					{
						head->right=temp;
						head=first;
						break;
					}
					else
						head=head->right;
				}
				else
				{
					if(temp->no <=head->no  )
					{
						if(head->left==NULL)
						{
							head->left=temp;
							head=first;
							break;
						}
						else
						{
							head=head->left;
						}
					}	
				}
			}
		}
		return first;
	}

	int search(Tree_node *root,int i)                //search function...
	{
		if(root->no==i)
		{
			cout<<"\nDATA FOUND\n";                
				return 1;
		}
		if(root->left==NULL && root->right==NULL)
		{
		
			cout<<"DATA NOT FOUND\n";
			return 0;	
				
		}
		else
		{
			if(i > root->no)
				search(root->right,i);
			if(i < root->no)
				search(root->left,i);
		}
		
	}
	
	void level_wise_display(Tree_node *root)
	{	                                     //level wise display....
		Tree_node *b;
		Tree_node *infi=new Tree_node;
		q.nqueue(root);
		infi->no=999;
		q.nqueue(infi);
		while(!q.empty())
		{
			b=q.dqueue();
			
			if(b->no!=infi->no)
			{					
				cout<<b->no<<" ";	
				if(b->left!=NULL)
				q.nqueue(b->left);
				if(b->right!=NULL)
				q.nqueue(b->right);	
			}
			else
			{
				if(!q.empty())		
					q.nqueue(infi);
				cout<<"\n";	
			}
			
		}
	}
	
	
	Tree_node *mirror_image(Tree_node * root)
	{                                                  //mirror image....
		Tree_node *temp1;
		if(root==NULL)
			return root;
		temp1=root->left;
		root->left=mirror_image(root->right);
		root->right=mirror_image(temp1);
		return root;	
	}
	
		int ser(float a)
		{
			for(int b=0;b<i;b++)
			{
				if(s[b]->no==a)
				return b;
			}
		}
		
		
		void inorder_r(Tree_node *root)          
		{				//inorder tree tree traversal...
			if(root!=NULL)
			{
				inorder_r(root->left);
				cout<<root->no<<" ";
				inorder_r(root->right);
			}
		}
	
		void inorder_r_t(Tree_node *root)
		{
			if(root!=NULL)
			{
				inorder_r_t(root->left);
				s[i]=root;
				i++;
				inorder_r_t(root->right);
			}
		}
		
		void del(Tree_node *root,float m)
		{
							//delete function.....
			inorder_r_t(root);
			int xx=ser(m);
			while(1)
			{
				if(root->left->no==m)
				{
					if(root->left->left==NULL && root->left->right ==NULL)
					{
						root->left=NULL;
						break;
					}
					if(root->left->left==NULL && root->left->right!=NULL)
					{
						root->left=s[++xx];
						break;
					}
					if(root->left->left!=NULL && root->left->right==NULL)
					{
						root->left=s[--xx];
						break;
					}
					if(root->left->right!=NULL && root->left->left !=NULL)
					{
						root->left=s[++xx];
						--xx;
						root->left->left=s[--xx];
						break;
					}	
					
				}
				else 
				{
				if(root->right->no==m)
				{
					if(root->right->left==NULL && root->right->right ==NULL)
					{
						root->right=NULL;
						break;
					}
					if(root->right->left==NULL && root->right->right!=NULL)
					{
						root->right=s[++xx];
						break;
					}
					if(root->right->left!=NULL && root->right->right==NULL)
					{	
						root->right=s[--xx];
						break;
					}
					if(root->right->right!=NULL && root->right->left !=NULL)
					{
						root->right=s[++xx];
						--xx;
						root->right->left=s[--xx];
						break;
					}
				}	
				else
				{
					if(m > root->no)		
						root=root->right;
					if(m < root->no)
						root=root->left;
					if(m==root->no)
					{
						root->no=s[++xx]->no;
						root->right=NULL;
						break;	
					}
				}							
			}
		}
	}		
		


			
};

int main()
{
	Tree t;
	Tree_node *root,*first;
	int a=1,i,ch;
	cout<<"\n\nTHIS PROGRAM ILLUSTRATES THE BINARY SEARCH TREE  ";
	do
	{
		cout<<"\n\n\tLIST OF OPERATIONS ";
		cout<<"\n\n\t\t1.CREATE  ";
		if(root!=NULL){
		cout<<"\n\n\t\t2.DISPLAY  ";
		cout<<"\n\n\t\t3.LEVEL WISE DISPLAY  ";
		cout<<"\n\n\t\t4.MIRROR IMAGE  ";
		cout<<"\n\n\t\t5.DELETE  ";
		cout<<"\n\n\t\t6.INSERT  ";
		cout<<"\n\n\t\t7.SEARCH  ";}
		cout<<"\n\n\t\t8.EXIT ";
		cout<<"\n\n\tENTER YOUR CHOICE : ";
		cin>>ch;	
		switch(ch)
		{
			case 1:

				while(a==1)
				{
					root=t.create();
					cout<<"\n\tCONTINUE (1/0) " ;
					cin>>a;
				}
				a=1;
				first=root;
			break;

			case 2:		t.inorder_r(root);
			
			break;

			case 4:
					first=t.mirror_image(first);
					cout<<"\n\nMIRROR IMAGE \n\n";
					t.level_wise_display(first);
					
			break;

			case 5 :
					cout<<"\n\n\t\tENTER THE NODE TO BE DELETED  ";
					cin>>i;
					t.del(root,i);
			break;

			case 6:  root= t.create();
			
			break;

			case 3 :	t.level_wise_display(root);
			break;
			
			case 8:    cout<<"\n\n\t\t\tTHANK-YOU!!!";
			break;

			case 7:  cout<<"\n\n\tENTER THE NUMBER TO BE SEARCHED   :  ";
				cin>>i;
				int y=t.search(root,i);

			break;
			
							
		}	
	}while(ch!=8);
}
	
