// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
float matrix[100][100],distances[100];
int visited_node[100],node[100],head=-1,tail=-1;
void Making_matrix(int node_number) {
	cout<<"-------Making matrix--------"<<'\n';
	for(int i=0; i<node_number; i++)
	{
		for(int j=0; j<node_number; j++)
		{
			cin>>matrix[i][j];
		}
	}
	cout<<"------------ the matrix--------"<<'\n';
	for(int i=0; i<node_number; i++)
	{
		for(int j=0; j<node_number; j++)
		{
			cout<<matrix[i][j]<<"  ";
		}

		cout<<'\n';
	}
	for(int i=0; i<node_number; i++)
	{
		distances[i]=999999;
	}

}

void Visited_node(int starting_node,int node_number)
{
	if(head==-1)
	{
		head++;
		node[head]=starting_node;

	}
	tail++;
	node[tail]=starting_node;
	distances[starting_node]=0;
	visited_node[starting_node]=1;

	while(head<=tail)
	{
		int team=node[head];
		//cout<<team<<"  ";
		head++;
		for(int i=0;i<node_number; i++)
		{
			if(matrix[team][i]!=0&&matrix[team][i]>0&&visited_node[i]!=1) {
				tail++;
				node[tail]=i;
				visited_node[i]=1;
				distances[i]=matrix[team][i];

				if(distances[i]>distances[team] + matrix[team][i])
				{
					distances[i] = distances[team] + matrix[team][i];
					//cout<<team<<"------->"<<i<<"------->"<<distances[i]<<'\n';
				}
				cout<<team<<"------->"<<i<<"------->"<<distances[i]<<'\n';
			}
		}
	}
}
int main() {
	int startng_node;
	int node_number;
	float total=0;
	cout<<"Enter node number: ";
	cin>>node_number;
	Making_matrix(node_number);

	cout<<"Enter the starting_node: ";
	cin>>startng_node;

	Visited_node(startng_node,node_number);
	cout<<'\n';
	for(int i=0; i<node_number; i++)
	{
		
		cout<<distances[i]<<"  ";
	}

	cout<<'\n'<<total;

	return 0;
}