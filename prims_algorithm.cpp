//SHRIRANG B BHALERAO
//ROLL NO - 8068
//TITLE - IMPLEMENTATION OF PRIM'S ALGORITHM

#include<iostream>
using namespace std;

#define infinity 9999;

class input
{
private:
	int vertices,edges,weight;
	int a[20][20],visit[20],parent[20],wt[20],vertex[20],b[20][20];
public:

	input()
	{
		for(int i=0;i<20;i++)
		{
			wt[i]=infinity;                 //DEFAULT CONSTRUCTOR....
			for(int j=0;j<20;j++)
				a[i][j]=0,visit[i]=0;
		}
	}

	void getdata()
	{
		cout<<"\n\tENTER NO OF VERTICES AND EDGES :  ";
		cin>>vertices>>edges;
		if(edges > (vertices *(vertices/2))|| vertices > 6 )
		{
			cout<<"\nINVALID INPUT ";                
			getdata();
		}
	}	
	
	void get_info()
	{
		getdata();
		int i=edges,j,k;             //FUNCTION TO INPUT ADJACENCY MATRIX....
 		while(i!=0)
		{
			cout<<"\n\tENTER EDGE AND WEIGHT :  ";
				cin>>j>>k>>weight;
			a[j][k]=weight;
			a[k][j]=weight;
			i--;
		}
	}
	
	void print()
	{
		for(int i=0;i<vertices;i++)
		{
			cout<<"\n";
			for(int j=0;j<vertices;j++)
			{
				cout<<a[i][j]<<"\t";       //FUNCTION TO PRINT ADJACENCY MATRIX...
			}
			
		}
	}
	
	int minimum()	
	{
		int k=infinity;
		int m=0;
		for(int i=0;i<vertices;i++)
		{
			if(k > wt[i] && !visit[i] )
			{
				k=wt[i];                      //RETURNS INDEX OF MINIMUM WEIGHT...
				m=i;
			}
		}
		return m; 
	}
	
	void prims(int p)	 //PRIMS ALGORITHM TO FIND MST AND MINIMUM COST....
	{													
		wt[p]=0;
		parent[p]= -1;
		int i=0,j,k;
		while(i < vertices-1)
		{
			j=minimum();
			for(k=0;k<vertices;k++)
			{	
				if( a[j][k] && a[j][k] < wt[k] && !visit[k])
				{	
					wt[k]=a[j][k];
					parent[k]=j;
				}
			}
			visit[j]=1;	
			i++;
		}

		for(int l=0;l<vertices;l++)
		{	
			if(l!=p)
			{
				cout<<"\n";
				cout<<l<<" - "<<parent[l];
			}
		}

		int sum=0;
		for(int i=0;i<vertices;i++)
		{
			sum=sum+wt[i];
		}
		cout<<"\n\n\tTOTAL COST =  "<<sum;
	}
};

int main()
{
	int p=0,q=0;
	cout<<"\nTHIS PROGRAM ILLUSTRATES IMPLEMENTATION OF PRIMS ALGORITHM ";
	cout<<"\n\nLIST OF CITIES WHERE OFFICES ARE LOCATED : ";
	cout<<"\n\n\t0.DELHI ";
	cout<<"\n\n\t1.PUNE ";
	cout<<"\n\n\t2.MUMBAI ";
	cout<<"\n\n\t3.CHENNAI ";
	cout<<"\n\n\t4.BANGLORE";
	cout<<"\n\n\t5.HYDRABAD ";
	cout<<"\n\nPLS ENTER THE CITY CODES TO ESTABLISH  CONNECTIVITY\n";
	input i;
	i.get_info();
	i.print();
	cout<<"\n\n\tDO U WANT TO ENTER ANY ANY SPECIFIC STARTING LOACTION (1/0) :  ";
	cin>>q;
	if(q)
	{
		cout<<"\n\n\tENTER LOCATION CODE :  ";
		cin>>p;
	}	
	i.prims(p);
}

/*THIS PROGRAM ILLUSTRATES IMPLEMENTATION OF PRIMS ALGORITHM 

LIST OF CITIES WHERE OFFICES ARE LOCATED : 

	0.DELHI 

	1.PUNE 

	2.MUMBAI 

	3.CHENNAI 

	4.BANGLORE

	5.HYDRABAD 

PLS ENTER THE CITY CODES TO ESTABLISH  CONNECTIVITY

	ENTER NO OF VERTICES AND EDGES :  6 9

	ENTER EDGE AND WEIGHT :  0 1 7000

	ENTER EDGE AND WEIGHT :  1 2 10000

	ENTER EDGE AND WEIGHT :  2 3 11000

	ENTER EDGE AND WEIGHT :  3 4 6000

	ENTER EDGE AND WEIGHT :  4 5 9000

	ENTER EDGE AND WEIGHT :  5 0 14000

	ENTER EDGE AND WEIGHT :  2 0 9000

	ENTER EDGE AND WEIGHT :  1 3 15000

	ENTER EDGE AND WEIGHT :  2 5 2000

0		7000		9000		0		0		14000	
7000		0		10000		15000		0		0	
9000		10000		0		11000		0		2000	
0		15000		11000		0		6000		0	
0		0		0		6000		0		9000	
14000		0		2000		0		9000		0	





	DO U WANT TO ENTER ANY ANY SPECIFIC STARTING LOACTION (1/0) :  0

1 - 0
2 - 0
3 - 4
4 - 5
5 - 2

	TOTAL COST =  33000

	DO U WANT TO ENTER ANY ANY SPECIFIC STARTING LOACTION (1/0) :  1

	ENTER LOCATION CODE :  5

0 - 2
1 - 0
2 - 5
3 - 4
4 - 5

	TOTAL COST =  33000
*/


