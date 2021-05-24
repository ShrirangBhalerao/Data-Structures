//SHRIRANG B BHALERAO
//ROLL NO - 8068
//TITLE - FRIEND'S NETWORK (GRAPH)



#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class friends
{
friend class graph;
private:
	char name[30];
	int day;
	int month;
	int year;
	int r_comments;

public:

	void getdata()
	{
		cout<<"\n\tENTER NAME :  ";
		cin>>name;
		cout<<"\n\tENTER BIRTH DATE :  ";
		cin>>day;
		cin>>month;
		cin>>year;
		cout<<"\n\tENTER THE COMMENTS RECEIVED ON THE RECENT POST UPDATED :   ";
		cin>>r_comments;
		
	}
};

class graph_node
{
	friend class graph;
private:
	friends h;
	graph_node *next;
public:

	graph_node()
	{
	next=NULL;
	}
};

class node
{	
	friend class stack;
	private:				//NODE CLASS DECLARED AS TEMPLATE...
		graph_node * ch;
		node *next;
};

class stack
{
	private: 
		node *sp,*temp;
	public:
		stack()
		{
			sp=NULL;                //STACK POINTER INITIALIZED TO NULL..
		}
	
		void push(graph_node  * a)
		{
			temp=new node;
			temp->ch=a;
			temp->next=sp;                  //PUSH FUNCTION.....
			sp=temp;	
		}

		graph_node* pop()
		{
			graph_node * a,*b;
			a=sp->ch;
			b=a;
			sp=sp->next;
			delete b;           //POP FUNCTION...
			return a;
		}

		int empty()
		{
			if(sp==NULL)
			return 1;
			return 0;
		}			
};

class queue_node
{

private:
friend class queue;
graph_node *ch;
queue_node *next;
};

class queue
{
private:
queue_node *front,*rear,*temp;
public:
	queue()
	{
		front=NULL;
		rear=NULL;
	}

	void nqueue(graph_node *a)
	{
		temp=new queue_node;
		temp->ch=a;
		if(front==NULL)
		{
			front=temp;
			rear=temp;
		}
		else
		{
			rear->next=temp;
		}		
	}
	
	graph_node *dqueue()
	{
		graph_node * a,*b;
		a=front->ch;
		b=a;
		front=front->next;
		delete b;
		return a;
	}
	
	int empty()
	{
		if(front==NULL )
			return 1;
		return 0;
	}
};

		
class graph
{

private:	
	int i;
	int c,u;
	graph_node *g[15];
	friends f[15];
	graph_node *temp;
	graph_node *gg,*hh,*xx;
	int visit[20];
	

	
public:

	graph()
	{
		temp=NULL;
		c=0;
	}
	
	void get_info()
	{
		cout<<"\n\n\tENTER THE NUMBER OF USERS  :  ";
		cin>>i;
		for(int j=0;j<i;j++)
			f[j].getdata();
	}


	void set_info()
	{
		int a=0;
		while(a<i)
		{						//adjacency list is created....
			temp=new graph_node;
			temp->h=f[a];	
			g[a]=temp;
			a++;
		}
	}


	int search(char a[])
	{
		int b=0;
		while(b<i)
		{
			if(strcmp(a,g[b]->h.name)==0)
			return b;
			b++;
		}
		return -1;
	}

	void ask_info()
	{
		char a[20][20],b[20];
		graph_node *v,*u,*s,*r;
		int z,y,x,t=0,q=0;
		cout<<"\n\n\t\tENTER THE NAME OF USER WHOSE FRIENDS ARE TO BE ENTERED :  ";
		cin>>b;
		y=search(b);
		if(y==-1)
			cout<<"\n\t\tUSER NOT FOUND   ";
		else
		{
			cout<<"\n\n\t\tENTER NUMBER OF FRIENDS :  ";
			cin>>z;
			
			v=g[y];
			u=new graph_node;
			u->h=g[y]->h;
			cout<<"\n\n\tENTER THE NAMES OF FRIENDS   :  ";
			for(int w=0;w<z;w++)
			{
				
				cin>>a[w];
				t=0;
				x=search(a[w]);
				r=g[x];
				if(x==-1)
					cout<<"\n\t\tUSER NOT FOUND ";
				else
				{
					if(strcmp(v->h.name,a[w])==0)
					cout<<"\n\n\t\tINVALID ENTRY ";
					else
					{
						while(v!=NULL)
						{	
							if(strcmp(v->h.name,a[w])==0)
							{
								t=1;
								break;
							}	
							v=v->next;
						}
						v=g[y];
						r=g[x];
						if(t==0)
						{
							s=new graph_node;
							s->h=g[x]->h;
							s->next=g[y]->next;
							g[y]->next=s;
							while(r!=NULL)
							{
								if(strcmp(r->h.name,u->h.name)==0)
								{
									q=1;
									break;
								}
								r=r->next;
							}
							r=g[x];
							if(q==0)
							{
								u->next=g[x]->next;
								g[x]->next=u;
							}
						}	
					}
				}		
			}
		}
	}						
					
							
	void disp_friends()
	{								
						//friend-list of user is displayed....		
		char b[30];
		graph_node *add;
		cout<<"\n\n\tWHOSE FRIEND-LIST WOULD U LIKE TO SEE :  ";
		cin>>b;
		int v=search(b);
		if(v==-1)
			cout<<b<<"\n\n\t\tDOES NOT HAVE A PROFILE ON FRIENDS_GROUP ";
		else
		{
			add=g[v];
			cout<<"\n\n\tFRIENDS OF "<<add->h.name<<" ARE \n";
			while(1)
			{
				cout<<"\n\t";
				cout<<add->next->h.name<<"  ";
				add=add->next;
				if(add->next==NULL)
				{
					return;
				}
			}
		}
	}
	
		
	void number_of_friends()
	{
		int d=0,j=0,a,b,c;
		int jj[20];                 //function gives the name of the with maximum friends...
		while(j!=20)
		{
			jj[j]=0;
			j++;
		}
		j=0;
		graph_node *one;
		while(d!=i && g[d]!=NULL)
		{
			one=g[d];
			one=one->next;
			while(one!=NULL)
			{
				jj[j]++;
				one=one->next;
			}
			j++;
			d++;
		}
		b=jj[0];
		c=0;
		for(a=1;a<i;a++)
		{
			if(jj[a]>b)
			{
				b=jj[a];
				c=a;
			}
			
		}
		cout<<"\n\n\t\t"<<g[c]->h.name<<"  HAS MAXIMUM  IE "<<b<<" FRIENDS";
	}
	

	void comments(int o)
	{
		stack s;                                  //function gives maximum and minimum commments...
		graph_node *a;
		int z,y,x,l=0,m=0,n=0,p=999;
		for(z=0;z<i;z++)
			visit[z]=0;
		s.push(g[o]);
		while(!s.empty())			//depth first search....
		{
			a=s.pop();
			x=search(a->h.name);
			if(l < a->h.r_comments)
			{
				l=a->h.r_comments;
				m=x;
			}
			if(p > a->h.r_comments)
			{
				p=a->h.r_comments;
				n=x;
			}	
			z=search(a->h.name);
			if(visit[z]==0)
			{
				visit[z]=1;
				a=a->next;
				while(1)
				{
					y=search(a->h.name);
					if(visit[y]==0)
					{
						s.push(g[y]);	
					}
					a=a->next;
					if(a==NULL)
					break;
				}			
			}	
		}
		cout<<"\n\n\t\t"<<g[m]->h.name<<"  HAS POSTED MAXIMUM IE  "<<l<<" COMMENTS";
		cout<<"\n\n\t\t"<<g[n]->h.name<<"  HAS POSTED MINIMUM IE  "<<p<<" COMMENTS";
	}
	
	
	void birthday(int p)
	{
		int m=0,n,l=0,j=0,z;
		graph_node *a;
		queue q;
		cout<<"\nENTER MONTH (1-12) :  ";
		cin>>m;
		int e[i];
		for(z=0;z<i;z++)
			visit[z]=0;
		
		q.nqueue(g[p]);
		cout<<"\nnqueue - "<<g[p]->h.name;
		if(g[p]->h.month==m)
		{
			e[l]=p;
			l++;
		}	
		visit[p]=1;
	
			while(q.empty()==0)
			{
				a=q.dqueue();
				cout<<"\ndqueue - "<<a->h.name;
				while(1)
				{
					
					n=search(a->next->h.name);
					if(visit[n]==0)
					{
						visit[n]=1;
						q.nqueue(g[n]);
							cout<<"\nnqueue - "<<g[n]->h.name;
						if(g[n]->h.month==m)
						{
							e[l]=n;
							l++;
						}
					}
					a=a->next;
					if(a->next==NULL)
					break;
				}
			}						
				
				
			cout<<"\n\n\tBIRTH-DAYS OF THIS MONTH\n ";
			for(int t=0;t<l;t++)
				cout<<"\n\t"<<g[e[t]]->h.name;
							
		}		
	};	
				




int main()
{
	graph g;
	int ch;
	do
	{
		cout<<"\n\n\tLIST OF OPERATIONS";
		cout<<"\n\n\t\t1.GET USER'S DATABASE ";
		cout<<"\n\n\t\t2.FRIENDSHIP ";
		cout<<"\n\n\t\t3.DISPLAY FRIEND-LIST";
		cout<<"\n\n\t\t4.MAXIMUM FRIENDS";
		cout<<"\n\n\t\t5.MAXIMUM AND MINIMUM  COMMENTS";
		cout<<"\n\n\t\t6.BIRTH-DAY'S IN THIS MONTH";
		cout<<"\n\n\t\t7.EXIT";
		cout<<"\n\n\tENTER YOUR CHOICE :  ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				g.get_info();
				g.set_info();	
				break;
			case 2:
				g.ask_info();
				break;
			case 3:
				g.disp_friends();
				break;
			case 4:
				g.number_of_friends();
				break;
			case 5: g.comments(0);
				break;
			case 6: g.birthday(0);
				break;
			case 7: cout<<"\n\n\t\t\tTHANK-YOU!!!";
				break;		
				
		}
	}while(ch!=7);
	
}	

/* output

	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  1


	ENTER THE NUMBER OF USERS  :  6

	ENTER NAME :  ASHISH

	ENTER BIRTH DATE :  1 3 2000

	ENTER THE COMMENTS RECEIVED ON THE RECENT POST UPDATED :   59

	ENTER NAME :  SAGAR

	ENTER BIRTH DATE :  19 8 2000

	ENTER THE COMMENTS RECEIVED ON THE RECENT POST UPDATED :   68

	ENTER NAME :  TANMAY

	ENTER BIRTH DATE :  15 3 2000

	ENTER THE COMMENTS RECEIVED ON THE RECENT POST UPDATED :   128

	ENTER NAME :  MITHILESH

	ENTER BIRTH DATE :  18 3 2000

	ENTER THE COMMENTS RECEIVED ON THE RECENT POST UPDATED :   359

	ENTER NAME :  VISHAL

	ENTER BIRTH DATE :  29 8 2000

	ENTER THE COMMENTS RECEIVED ON THE RECENT POST UPDATED :   200

	ENTER NAME :  PARAS

	ENTER BIRTH DATE :  9 8 2000

	ENTER THE COMMENTS RECEIVED ON THE RECENT POST UPDATED :   50


	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  2


		ENTER THE NAME OF USER WHOSE FRIENDS ARE TO BE ENTERED :  ASHISH


		ENTER NUMBER OF FRIENDS :  2


	ENTER THE NAMES OF FRIENDS   :  SAGAR
TANMAY


	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  2


		ENTER THE NAME OF USER WHOSE FRIENDS ARE TO BE ENTERED :  SAGAR


		ENTER NUMBER OF FRIENDS :  5


	ENTER THE NAMES OF FRIENDS   :  ASHISH
TANMAY
MITHILESH
VISHAL
PARAS


	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  2


		ENTER THE NAME OF USER WHOSE FRIENDS ARE TO BE ENTERED :  TANMAY


		ENTER NUMBER OF FRIENDS :  4


	ENTER THE NAMES OF FRIENDS   :  ASHISH
SAGAR
MITHILESH
VISHAL


	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  2


		ENTER THE NAME OF USER WHOSE FRIENDS ARE TO BE ENTERED :  MITHILESH


		ENTER NUMBER OF FRIENDS :  4


	ENTER THE NAMES OF FRIENDS   :  SAGAR
TANMAY
VISHAL
PARAS


	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  2


		ENTER THE NAME OF USER WHOSE FRIENDS ARE TO BE ENTERED :  VISHAL


		ENTER NUMBER OF FRIENDS :  3


	ENTER THE NAMES OF FRIENDS   :  SAGAR
TANMAY
MITHILESH


	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  2


		ENTER THE NAME OF USER WHOSE FRIENDS ARE TO BE ENTERED :  PARAS


		ENTER NUMBER OF FRIENDS :  2


	ENTER THE NAMES OF FRIENDS   :  SAGAR
MITHILESH


	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  3


	WHOSE FRIEND-LIST WOULD U LIKE TO SEE :  PARAS


	FRIENDS OF PARAS ARE 

	MITHILESH  
	SAGAR  

	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  3


	WHOSE FRIEND-LIST WOULD U LIKE TO SEE :  VISHAL


	FRIENDS OF VISHAL ARE 

	MITHILESH  
	TANMAY  
	SAGAR  

	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  3


	WHOSE FRIEND-LIST WOULD U LIKE TO SEE :  MITHILESH


	FRIENDS OF MITHILESH ARE 

	PARAS  
	VISHAL  
	TANMAY  
	SAGAR  

	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  3


	WHOSE FRIEND-LIST WOULD U LIKE TO SEE :  TANMAY


	FRIENDS OF TANMAY ARE 

	VISHAL  
	MITHILESH  
	ASHISH  
	SAGAR  

	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  3


	WHOSE FRIEND-LIST WOULD U LIKE TO SEE :  SAGAR


	FRIENDS OF SAGAR ARE 

	PARAS  
	VISHAL  
	MITHILESH  
	TANMAY  
	ASHISH  

	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  3


	WHOSE FRIEND-LIST WOULD U LIKE TO SEE :  ASHISH


	FRIENDS OF ASHISH ARE 

	TANMAY  
	SAGAR  

	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  4


		SAGAR  HAS MAXIMUM  IE 5 FRIENDS

	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  5


		MITHILESH  HAS POSTED MAXIMUM IE  359 COMMENTS

		PARAS  HAS POSTED MINIMUM IE  50 COMMENTS

	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  6

ENTER MONTH (1-12) :  3

	BIRTH-DAYS OF THIS MONTH
 
	ASHISH
	TANMAY
	MITHILESH

	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  6

ENTER MONTH (1-12) :  8

	BIRTH-DAYS OF THIS MONTH
 
	SAGAR
	VISHAL
	PARAS

	
	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  2


		ENTER THE NAME OF USER WHOSE FRIENDS ARE TO BE ENTERED :  RAHUL

		USER NOT FOUND   

	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  2


		ENTER THE NAME OF USER WHOSE FRIENDS ARE TO BE ENTERED :  SAGAR


		ENTER NUMBER OF FRIENDS :  1


	ENTER THE NAMES OF FRIENDS   : SAGAR


		INVALID ENTRY 

	LIST OF OPERATIONS

		1.GET USER'S DATABASE 

		2.FRIENDSHIP 

		3.DISPLAY FRIEND-LIST

		4.MAXIMUM FRIENDS

		5.MAXIMUM AND MINIMUM  COMMENTS

		6.BIRTH-DAY'S IN THIS MONTH

		7.EXIT

	ENTER YOUR CHOICE :  7


			THANK-YOU!!!
*/

