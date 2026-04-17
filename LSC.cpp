// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
	string x,y;
	int dt[100][100],max1=0;
	cout<<"Enter the first string :";
	cin>>x;
	cout<<"Enter the 2nd string: ";
	cin>>y;

	for(int i=0; i<=x.length(); i++)
	{
		for(int j=0; j<=y.length(); j++)
		{
			if(i==0|| j==0)
			{
				dt[i][j]=0;
			}
			else if(x[i]==y[j])
			{
				dt[i][j]=1+dt[i-1][j-1];
			}
			else
			{
				dt[i][j]=max(dt[i-1][j],dt[i][j-1]);

			}
		}
	}
	for(int i=0; i<=x.length(); i++)
	{
		for(int j=0; j<=y.length(); j++)
		{
			cout<<dt[i][j];
			max1=max(max1,dt[i][j]);
		}
		cout<<'\n';

	}
	cout<<'\n'<<max1;




	return 0;
}