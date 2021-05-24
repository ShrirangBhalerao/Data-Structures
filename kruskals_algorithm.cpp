//SHRIRANG B BHALERAO
//ROLL NO - 8068
//TITLE - IMPLEMENTATION OF KRUSKALS ALGORITHM


#include<iostream>
using namespace std;

class input
{
	friend class graph;
private :
	int u1,u2,w;
public:
	void getdata()
	{
		cout<<"\n\tENTER EDGE AND WEIGHT :  ";
		cin>>u1>>u2>>w;
	}
};

class graph
{
private:
	input i[20],temp;
	int vertices,edges,g[20][3],cost=0,j=0,set[20];

public:

	graph()
	{
		for(int j=0;j<20;j++)
		set[j]=j;
	}		

	void get_info()
	{
		cout<<"\n\tENTER NUMBER OF VERTICES AND EDGES :  ";
		cin>>vertices>>edges;
		for(int j=0;j<edges;j++)
			i[j].getdata();
		
	}
	
	void sort()
	{
		for(int j=1;j<edges;j++)
			for(int k=0;k<edges-j;k++)
			{
				if(i[k].w > i[k+1].w)
				{
					temp=i[k];
					i[k]=i[k+1];
					i[k+1]=temp;
				}
			}	
	}

	void kruskals_algo()
	{
		sort();
		int a=0,b=0,s=1;
		while(a!=(vertices-1))
		{
			if(set[i[b].u1]!=set[i[b].u2])
			{					
				g[j][0]=i[b].u1;
				g[j][1]=i[b].u2;	
				g[j][2]=i[b].w;
				int q=set[i[b].u1];
				int r=set[i[b].u2];
				cost=cost+i[b].w;
				for(int z=0;z<vertices;z++)
				{
					if(set[z]==r)
					set[z]=q;
				}
				j++,b++,a++;
			}
			else
			{
				b++;
			}
		}
	}
	
	void print()
	{
		cout<<"\n\n\tEDGES OF GRAPH\n";
		for(int y=0;y<j;y++)
		{
			cout<<"\n";
			for(int q=0;q<3;q++)
			{
				cout<<g[y][q]<<"\t";
			}
		}
		cout<<"\n\n\tCOST OF GRAPH :  "<<cost;
	}
};

int main()
{
	graph g;
	g.get_info();
	g.kruskals_algo();
	g.print();
}



	/*ENTER NUMBER OF VERTICES AND EDGES :  6 9 

	ENTER EDGE AND WEIGHT :  0 1 7

	ENTER EDGE AND WEIGHT :  1 2 10

	ENTER EDGE AND WEIGHT :  2 3 11

	ENTER EDGE AND WEIGHT :  3 4 6

	ENTER EDGE AND WEIGHT :  4 5 9

	ENTER EDGE AND WEIGHT :  5 0 14

	ENTER EDGE AND WEIGHT :  0 2 9

	ENTER EDGE AND WEIGHT :  1 3 15

	ENTER EDGE AND WEIGHT :  2 5 2


	EDGES OF GRAPH

2	5	2	
3	4	6	
0	1	7	
4	5	9	
0	2	9	

	COST OF GRAPH :  33*/





