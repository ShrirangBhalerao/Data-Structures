#include<iostream>
#include<stdlib.h>
using namespace std;

class Patient
{
	friend class Hospital;
	friend class queue;
	
	private:
		char name[30];
		char disease[30];
		int age;
		int priority;

		Patient *next;
};


class Hospital
{
public:
	Patient *temp,*obj;

	void New_patient(Patient *temp)
	{
	
		cout<<"\nEnter Name -  ";
		cin>>temp->name;
		cout<<"\nEnter Age -  ";
		cin>>temp->age;
		cout<<"\nEnter Disease -  ";
		cin>>temp->disease;
		cout<<"\nEnter Priority - ";
		cin>>temp->priority;
	
	}

	void display(Patient *temp)
	{
		cout<<"\nName - "<<temp->name<<endl;
		cout<<"\nage- "<<temp->age<<endl;
		cout<<"\ndisease- "<<temp->disease<<endl;
		cout<<"\npriority - "<<temp->priority<<endl<<endl;
	}

	void record(Patient *obj)
	{
		int i=0;
		while(obj!=NULL)
		{
			if(obj->priority==1)
			{	
				cout<<"\nSERIOUS PATIENTS\n\n";
				while(obj->priority==1)
				{
					cout<<"\t"<<++i<<".\t"<<obj->name<<"\n";
					obj=obj->next;
					if(obj==NULL)
					break;
				}
			
			}
			else
			{
				i=0;
				if(obj->priority == 2)
				{
					cout<<"\nMEDIUM CASE PATIENTS\n\n";
					while(obj->priority==2)
					{
						cout<<"\t"<<++i<<".\t"<<obj->name<<"\n";
						obj=obj->next;
						if(obj==NULL)
						break;
					}
				}
				else
				{
					i=0;
					cout<<"\nNORMAL CASE PATIENTS\n\n";
					while(obj!=NULL)
					{
						cout<<"\t"<<++i<<".\t"<<obj->name<<"\n";
						obj=obj->next;
						if(obj==NULL)
						break;			
					}
				}
			}
		}
	}
		
};

class queue
{
public:
	Patient *sp ,*temp,*head,*qp;
public:
	Hospital p;
	
	queue()
	{
		sp=NULL;
		head=NULL;
	}

	Patient * nqueue()
	{	
		temp=new Patient;
	
		p.New_patient(temp);
	
		if(sp==NULL)
		{
			head=temp;
			sp=temp;
		}
		else
		{	
			while(1)
			{
				if(head->next==NULL)
				{
					if(head->priority > temp->priority)
					{
						temp->next=head;
						head=temp;
						sp=head;
						break;
					}
					else
					{
						head->next=temp;
						head=sp;
						break;
					}
				}
				else
				{
					if(head->next->priority > temp->priority)
					{
						if(head->priority > temp->priority)
						{
							temp->next=head;
							head=temp;
							sp=head;
							break;
						}
						else
						{	
							temp->next=head->next;
							head->next=temp;
							head=sp;
							break;
						}
					}			
					else
					{
						head=head->next;	
					}
				}
			}	
		}		
		return sp;
	}	


	Patient * dqueue()
	{	
			Hospital p;
		
			if(sp==NULL)
				cout<<"\n\n\tALL PATIENTS HAVE BEEN TREATED\n  ";	
			else
			{
				p.display(sp);
				sp=sp->next;
				return sp;
			}
	}	

};





int main()
{
	cout<<"THIS PROGRAM FEATURES IMPLEMENTATION OF QUEUE USING C++"<<endl<<endl;
	queue s ;
	Patient *z;
	z=NULL;
	Hospital h;
	int a,b;
	do
	{
		cout<<"\n\tLIST OF OPERATIONS\n ";
		cout<<"\n\t\t1.NEW ADMISSION\n ";
		cout<<"\n\t\t2.DOCTOR'S VISIT\n ";
		cout<<"\n\t\t3.PATIENTS RECORD\n ";
		cout<<"\n\t\t4.EXIT\n ";
		cout<<"\n\t\t\tENTER YOUR OPTION :   ";
		cin>>a;
		switch(a)
		{
			case 1:	z=s.nqueue();
			break;
			case 2: z=s.dqueue();
			break;
			case 3:
				if(z==NULL)
					cout<<"\nALL PATIENTS HAVE BEEN DISCHARGED\n ";
				else	
					 h.record(z);
			break;
			
		}	

	}while(a!=4);


}






















                                                                                                                                                                                                                                  












































