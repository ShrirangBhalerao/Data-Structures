#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

template<class T>
class node
{	
	
	template<class U>friend class stack;
	friend class expression;
	private:				//NODE CLASS DECLARED AS TEMPLATE...
		T ch;
		node<T> *next;
};

template<class T>
class stack
{
	private: 
		node<T> *sp,*temp;
	public:
		stack()
		{
			sp=NULL;                //STACK POINTER INITIALIZED TO NULL..
		}
	
		void push(T a)
		{
			temp=new node<T>;
			temp->ch=a;
			temp->next=sp;                  //PUSH FUNCTION.....
			sp=temp;	
		}

		T pop()
		{
			char a;
			a=sp->ch;
			sp=sp->next;           //POP FUNCTION...
			return a;
		}

		int end()
		{
			if(sp==NULL)
			return 1;
		}
	
		char give()
		{
			return sp->ch;
		}	
};


class expression
{
public:
	char postfix[30],infix[30],prefix[30],se[30];
	stack<char>s;
	node<char> *sp;
	void getdata()
	{	
		cout<<"\n\tINSTRUCTIONS REGARDING EXPRESSION\n\n";
		cout<<"\t\t1.EXPRESSION SHOULD CONTAIN ONLY 3 VARIABLES\n";
		cout<<"\t\t2.EXPRESSION SHOULD START AND END WITH PARANTHESIS\n\n";
		while(1)
		{
			cout<<"ENTER THE EXPRESSION :   ";
			cin>>infix;
			if(infix[0]!='(')
				cout<<"INVALID EXPRESSION\n\n";
			else 
				break;
		}		
	}

	void display(char a[])
	{
		cout<<a;
	}

	void infix_to_postfix()
	{
		int i,j=0,k,length=0;
		char t,u;
		for(i=0;infix[i]!='\0';i++)
		{
			length++;
		}
		for(i=0;i<length;i++)        //infix_to_postfix CONVERSION        
		{
			t=infix[i];
			
			if(isalnum(t))
			{
				postfix[j++]=t;
			}
			else
			{
				if(t=='(')
					s.push(t);
						if(t=='+'||t=='-')
						{
							if(s.give()=='(')	
								s.push(t);
							else
		if(s.give()=='+'||s.give()=='-'||s.give()=='*'||s.give()=='/')
							{
								
									u=s.pop();
									postfix[j++]=u;
									s.push(t);
							}
						}
						if(t=='*'||t=='/')				
						{
									if(s.give()=='(')	
										s.push(t);
							else	
								if(s.give()=='*'||s.give()=='/')
								{
							
									u=s.pop();
									postfix[j++]=u;
									s.push(t);
								}
								if(s.give()=='+'||s.give()=='-')
								{
										s.push(t);
								}
						}
						if(t==')')
						{
							while(s.give()!='(')
							{
								u=s.pop();
								postfix[j++]=u;
							}
							u=s.pop();
						}						
					}
		}
		postfix[j]='\0';
		cout<<"\n\tPOST-FIX CONVERSION - ";display(postfix);	
		cout<<endl;	
	}

void infix_to_prefix()
{
	int i,j,l=0;
	char t,u;
	l=strlen(infix);		
	for(i=0;i<l;i++)                        //Infix_to_prefix CONVERSION....
	{
		se[i]=infix[i];
	}

	for(i=0,j=l-1;i<j;i++,j--)
	{
		t=se[i];
		se[i]=infix[j];
		se[j]=t;
	}
 	j=0;

	for(i=0;i<l;i++)
	{
		t=se[i];
		if(isalnum(t))
		{
			prefix[j++]=t;
		}
		else
		{
			if(t==')')
				s.push(t);
			if(t=='+'||t=='-')
			{
				if(s.give()==')')	
					s.push(t);
				else
				if(s.give()=='+'||s.give()=='-'||s.give()=='*'||s.give()=='/')
				{					
					u=s.pop();
					prefix[j++]=u;
					s.push(t);
				}
			}
			if(t=='*'||t=='/')				
			{
				if(s.give()==')')	
					s.push(t);
				else	
					if(s.give()=='*'||s.give()=='/')
					{		
						u=s.pop();
						prefix[j++]=u;
						s.push(t);
					}
					if(s.give()=='+'||s.give()=='-')
					{
						s.push(t);
					}
			}
			if(t=='(')
			{
				while(s.give()!=')')
				{
					u=s.pop();
					prefix[j++]=u;
				}
				u=s.pop();
			}						
	
		}
	}
	prefix[j]='\0';
	int p=strlen(prefix);
	for(i=0,j=p-1;i<j;i++,j--)
	{
		t=prefix[i];
		prefix[i]=prefix[j];
		prefix[j]=t;
	}
		cout<<"\n\tPRE-FIX CONVERSION - ";display(prefix);
		cout<<endl;	
	}

	void postfix_evaluation(int xx,int yy,int zz)
	{
		infix_to_postfix();
		node<int> *sp;
		stack<int> p;
		char a;
		int m;
		float n,o;
		m=strlen(postfix);
		for(int i=0;i<m;i++)
		{
			a=postfix[i];
			if(isalnum(a))              //postfix_evaluation....
			{
				switch(a)
				{
					case 'A':p.push(xx);
						break; 		
					case 'B':p.push(yy);
						break;
					case 'C':p.push(zz);
						break;
					case 'a':p.push(xx);
						break; 		
					case 'b':p.push(yy);
						break;
					case 'c': p.push(zz);
						break;
				}
			}
			else
			{
				switch(a)
				{
					case '+':
						n=p.pop();
						o=p.pop();
						p.push(n+o);
						break;
					case '-':
						n=p.pop();
						o=p.pop();
						p.push(o-n);
						break;
					case '*':
						n=p.pop();
						o=p.pop();
						p.push(n*o);
						break;
					case '/':
						n=p.pop();
						o=p.pop();
						p.push(o/n);
						break;	
				}
			}		
			
		}
		cout<<"\n\n\tPOST-FIX EVALUATION = "<<p.pop();
		cout<<endl;
	}	
		
void prefix_evaluation(int xx,int yy,int zz)
{		
		infix_to_prefix();
		node<int> *sp;
		stack<int> p;
		char a;
		int m;
		float n,o;
		m=strlen(prefix);
		for(int i=m-1;i>=0;i--)                    //prefix_evaluation...
		{
			a=prefix[i];
			if(isalnum(a))
			{
				switch(a)
				{
					case 'A':p.push(xx);
						break; 		
					case 'B':p.push(yy);
						break;
					case 'C':p.push(zz);
						break;
					case 'a':p.push(xx);
						break; 		
					case 'b':p.push(yy);
						break;
					case 'c': p.push(zz);
						break;
				}
			}
			else
			{
				switch(a)
				{
					case '+':
						n=p.pop();
						o=p.pop();
						p.push(n+o);
						break;
					case '-':
						n=p.pop();
						o=p.pop();
						p.push(n-o);
						break;
					case '*':
						n=p.pop();
						o=p.pop();
						p.push(n*o);
						break;
					case '/':
						n=p.pop();
						o=p.pop();
						p.push(n/o);
						break;	
				}
			}		
			
		}
		cout<<"\n\n\tPRE-FIX EVALUATION = "<<p.pop();
		cout<<endl;
	}	
		
};	


int main()
{
	int ch,a,b,c; 
	expression e;
	e.getdata();
	do
	{
		cout<<"\n\n\tLIST OF OPERATIONS\n\n";
		cout<<"\t1.POST-FIX CONVERSION\n";
		cout<<"\t2.PRE-FIX CONVERSION\n";              //MENU DRIVEN PROGRAM.....
		cout<<"\t3.POST-FIX EVALUATION\n";
		cout<<"\t4.PRE-FIX EVALUATION\n";
		cout<<"\t5.EXIT\n";
		cout<<"\t\tENTER YOUR CHOICE :  ";
		cin>>ch;
		switch(ch)
		{
			case 1: e.infix_to_postfix();		
				break;
			case 2: e.infix_to_prefix();	
				break;
			case 3: cout<<"\n\tENTER VALUES OF A,B,C : ";
				cin>>a>>b>>c; 
				e.postfix_evaluation(a, b, c);
				break;
			case 4:cout<<"\n\tENTER VALUES OF A,B,C : ";
				 cin>>a>>b>>c; 
				e.prefix_evaluation( a, b, c);
				break;
			case 5:"\n\n\t\t\tTHANK-YOU!!";
				break;	
			default: cout<<"\nINVALID-OPTION\n";
				break;	
		}
	}while(ch!=5);
}



	


