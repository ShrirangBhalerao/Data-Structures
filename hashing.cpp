#include<iostream>
using namespace std;

class hashing
{
friend class table;
private:
	long int phone_no;
	char name[30];
	int link;
public:
	hashing()
	{
		phone_no = -1;
		link = -1;
	}

	void display(int a)
	{
		cout<<"\n";
		cout<<"\t"<<a<<"\t";
		if(phone_no == -1)
			cout<<"...";
		else
			cout<<phone_no;
		cout<<"\t"<<link;
		
	}
			
	void disp1()
	{
		cout<<"\n\n\t\tNAME :   "<<name;
		cout<<"\n\n\t\tPHONE NUMBER :   "<<phone_no;
	}	
			
	void getdata()
	{
		cout<<"\n\n\tENTER NAME :  ";
		cin>>name;
		cout<<"\n\n\tENTER NUMBER :  ";
		cin>>phone_no;
	}
		
};


	
class table
{
private:
	int x;
	hashing h1[20];
public:

	void get_info()
	{
		cout<<"ENTER NUMBER OF STUDENTS :  ";
		cin>>x;
	}

	inline int mod(int a)
	{
		return a%x;
	}

	void insert()
	{
		int b,c=0,d=0;
		long int a;
		hashing o;
		o.getdata();
		a=mod(o.phone_no);
		b=a;
		while(1)
		{
			if(h1[a].phone_no==-1)
			{
				h1[a]=o;
				while(c<x)
				{		
					if( a!=b && h1[b].link==-1 && mod(h1[a].phone_no)==mod(h1[b].phone_no))
					{
						h1[b].link=a;
						break;
					}
					else
					{
						if(b==a)
							break;
						else
						{	
							b=h1[b].link;
							c++;
						}
					}
				}
				break;				
			}							
			else
			{
				a++;
				d++;
				if(a==x)
					a=0;
				if(d==x)
				{	
					cout<<"insufficient space ";
					break;
				}
			}
		}		
	}

	void insert_replace()
	{
		int b,c=0,d,e=0;
		long int a;
		hashing h;
		h.getdata();
		a=mod(h.phone_no);
		b=a;
		while(1)
		{
			if(h1[a].phone_no==-1)
			{
				h1[a]=h;
				while(c<x)
				{
					if(a==b)
						break;
					else
					{
			if(h1[b].link==-1 && mod(h1[a].phone_no)==mod(h1[b].phone_no))			
			{
				h1[b].link=a;
				break;
			}
			else
			{
				b=h1[b].link;
				c++;
			}
			}
			}
			break;
			}
			else
			{
				if(b!=mod(h1[b].phone_no))
				{
					int i=0;
					while(h1[a].phone_no!=-1)
					{
						a++;
						if(a==x)
						a=0;
					}
					i=mod(h1[b].phone_no);
					while(h1[i].link !=b)
						i=h1[i].link;
					h1[i].link=h1[b].link;
					while(h1[i].link !=-1)
						i=h1[i].link;
					h1[i].link=a;
					h1[a] = h1[b];
					h1[b].link=-1;
					h1[a].link=-1;
					h1[b]=h;
					h1[b].link=-1;
					break;						
				}
				else
				{
					a++;
					e++;
					if(a==x)
						a=0;
					if(e==x)
					{
						cout<<"\n\n\tinsufficient space ";
						break;
					}
				}
			}
		}			

	}
			
	void disp()
	{	
		for(int i=0;i<x;i++)
				h1[i].display(i);
	}

	void search()
	{
		int a,c=0,d=0;
		long int b;
		cout<<"\n\n\tENTER THE PHONE NO TO BE SEARCHED :  ";
		cin>>a;
		b=mod(a);
		while(d<x)
		{
			if(h1[b].phone_no == a)
			{
				c++;
				cout<<"\n\n\tDATA FOUND ";
				h1[b].disp1();
				cout<<"\n\n\tNUMBER OF COMPARISONS :  "<<c;
				break;
			}
			else
			{
				if(h1[b].link == -1)
				{
					if(b!=mod(h1[b].phone_no))
					{
						c++;
						b++;
						d++;
					}
					else
					{
						cout<<"\n\n\tDATA NOT FOUND ";
						break;
					}
				}
				else
				{
					c++;
					b=h1[b].link;
					d++;
				}
			}
		}
	}

	void delet()
	{
		int a,b,c,s,n;
		cout<<"\n\n\tENTER THE NO TO BE DELETED :  ";
		cin>>a;
		b=mod(a);
		if(h1[b].phone_no==-1)
			cout<<"\n\n\tNUMBER NOT FOUND ";
		else
		{
			s:
			if(h1[b].phone_no==a)
			{
				if(h1[b].link==-1 )
				{
					h1[b].phone_no=-1;
				}
				else
				{
					c=h1[b].link;
					h1[b]=h1[c];
					h1[c].phone_no=-1;
					h1[c].link=-1;	
				}
			}
			else
			{
				while(h1[b].phone_no !=a )
				{
					n=b;
					b=h1[b].link;
					if(b==-1)
					{
						cout<<"\n\n\tNUMBER NOT FOUND ";
						return;
					}
					
				}
				if(h1[b].link==-1)
				h1[n].link=-1;
				
				goto s;
			}				

		}
	}

};

int main()
{
	table t;
	t.get_info();
	int y,a;
	do
	{
		cout<<"\n\n\tLIST OF OPERATIONS ";
		cout<<"\n\n\t\t1.INSERT ";
		cout<<"\n\n\t\t2.DISPLAY ";
		cout<<"\n\n\t\t3.SEARCH ";
		cout<<"\n\n\t\t4.INSERT WITH REPLACEMENT ";
		cout<<"\n\n\t\t5.DELETE ";
		cout<<"\n\n\t\t6.EXIT ";
		cout<<"\n\n\tENTER YOUR CHOICE :   ";
		cin>>y;
		switch(y)
		{
			case 1:
				t.insert();
				break;
			case 2:
				t.disp();
				break;
			case 3: t.search();
				break;
			case 6:
				cout<<"\n\n\t\t\tTHANK-YOU!!!";
				break;
			case 4: t.insert_replace();
				break;
			case 5: t.delet();
				break;
		}
	}while(y!=6);
}








		
