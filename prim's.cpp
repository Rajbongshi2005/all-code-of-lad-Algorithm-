// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
float matrix[100][100],distances=0;
int visited_node[100];
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


}
void Visited_node(int node_number) {

	visited_node[0]=1;
	for(int i=0; i<node_number-1; i++)
	{
		int a=-1,b=-1,team=99999;

		for(int j=0; j<node_number; j++)
		{
			if(visited_node[j]==1)
			{
				for(int z=0; z<node_number; z++)
				{
					if(visited_node[z] == 0 && matrix[j][z] != 0 && matrix[j][z] < team)
					{
						a = j;
						b = z;
						team = matrix[j][z];
					}
				}
			}
		}
		if(a!=-1&& b!=-1)
		{
			cout<<a<<"------>"<<b<<"==="<<matrix[a][b]<<'\n';
			visited_node[b]=1;
			distances+=matrix[a][b];
		}
	}
}
int main() {

	int node_number;

	cout<<"Enter node number: ";
	cin>>node_number;
	Making_matrix(node_number);
	Visited_node(node_number);
	cout<<'\n';


	cout<<'\n'<<distances;

	return 0;
}