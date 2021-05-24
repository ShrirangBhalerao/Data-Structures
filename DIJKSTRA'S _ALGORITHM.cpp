//SHRIRANG B BHALERAO
//ROLL NO - 8068
//TITLE - IMPLEMENTATION OF DIJKSTRA'S ALGORITHM


#include<iostream>
using namespace std;

#define infinity 9999

class graph
{
private:
	int visit[20],a[20][20],wt[20],parent[20];
	int edges,vertices,weight;
public:

	graph()
	{
		for(int i=0;i<20;i++)
			for(int j=0;j<20;j++)
			{
				a[i][j]=0;
				visit[i]=0;
				wt[i]=infinity;
			}
	}

	int minimum()
	{
		int k=infinity,l=0;
		for(int i=0;i<vertices;i++)
		{
			if(wt[i] < k && visit[i]==0)
			{
				k=wt[i];
				l=i;
			}
		}
		return l;
	}

	void getdata()
	{
		int i,j,k;
		cout<<"\n\tENTER THE NUMBER OF  VERTICES AND EDGES  :  ";
		cin>>vertices>>edges;
		for(k=0;k<edges;k++)
		{
			cout<<"\n\tENTER EDGE AND WEIGHT :  ";
			cin>>i>>j>>weight;
			a[i][j]=weight;
			a[j][i]=weight;
		}
	}

	void dijkstras_algo(int p)
	{
		wt[p]=0;
		parent[p]=-1;
		int s=1,v=0,m,n=0;
		while( n < (vertices-1)) 
		{
			m=minimum();
			for(int i=0;i<vertices;i++)	
			{		
				if(a[m][i] &&  visit[i]==0 )
				{
					v=wt[m]+a[m][i];
					if(v < wt[i])
					{
						wt[i]=v;
						parent[i]=m;
						
					}
				}
			}
			visit[m]=s;
			n++;	
		}	
		for(int i=0;i<vertices;i++)
		{
			if(i!=p)
			{
				int j;
				cout<<"\n\n\t COST =  "<<wt[i];
				cout<<"\n\t PATH = "<<i;
				j=i;
				do
				{
					j=parent[j];
					cout<<" < - "<<j;
				}while(j!=p);
			}	
		}
	}

	void print()
	{
		cout<<"\n\n\tADJACENCY MATRIX\n ";
		for(int i=0;i<vertices;i++)
		{
			cout<<"\n";
			for(int j=0;j<vertices;j++)
				cout<<a[i][j]<<"\t";
		}
	}
};

int main()
{
	int i=0,j=0;
	graph g;
	g.getdata();
	g.print();
	cout<<"\n\nDO U WANT TO ENTER ANY SOURCE  VERTEX ? (1/0)  ";
	cin>>j;
	if(j)
	{
		cout<<"\n\n\tENTER THE SOURCE VERTEX :  ";
		cin>>i;
	}
	g.dijkstras_algo(i);
}



	/*ENTER THE NUMBER OF  VERTICES AND EDGES  :  6 9

	ENTER EDGE AND WEIGHT :  0 1 7

	ENTER EDGE AND WEIGHT :  1 2 10 

	ENTER EDGE AND WEIGHT :  2 3 11

	ENTER EDGE AND WEIGHT :  3 4 6

	ENTER EDGE AND WEIGHT :  4 5 9

	ENTER EDGE AND WEIGHT :  5 0 14

	ENTER EDGE AND WEIGHT :  0 2 9

	ENTER EDGE AND WEIGHT :  1 3  15

	ENTER EDGE AND WEIGHT :  2 5 2


	ADJACENCY MATRIX
 
0	7	9	0	0	14	
7	0	10	15	0	0	
9	10	0	11	0	2	
0	15	11	0	6	0	
0	0	0	6	0	9	
14	0	2	0	9	0	

DO U WANT TO ENTER ANY SOURCE  VERTEX ? (1/0)  0


	 COST =  7
	 PATH = 1 < - 0

	 COST =  9
	 PATH = 2 < - 0

	 COST =  20
	 PATH = 3 < - 2 < - 0

	 COST =  20
	 PATH = 4 < - 5 < - 2 < - 0

	 COST =  11
	 PATH = 5 < - 2 < - 0

DO U WANT TO ENTER ANY SOURCE  VERTEX ? (1/0)  1


	ENTER THE SOURCE VERTEX :  5


	 COST =  11
	 PATH = 0 < - 2 < - 5

	 COST =  12
	 PATH = 1 < - 2 < - 5

	 COST =  2
	 PATH = 2 < - 5

	 COST =  13
	 PATH = 3 < - 2 < - 5

	 COST =  9
	 PATH = 4 < - 5*/


