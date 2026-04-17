// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void quicksort(float arr[],int low,int high)
{
	if(low<=high)
	{
		int pivot=arr[high];
		int i=low-1;

		for(int j=low; j<high; j++)
		{
			if(arr[j]<pivot)
			{
				i++;
				swap(arr[i],arr[j]);
			}
		}
		swap(arr[i+1],arr[high]);
		int pi=i+1;

		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);

	}
}

int main() {
	float arra[100];
	int array_size;
	cout<<"Enter the array size: ";
	cin>>array_size;
	cout<<"Enter the array: \n";
	for(int i=0; i<array_size; i++)
	{
		cin>>arra[i];
	}
	quicksort(arra,0,array_size-1);
	for(int i=0; i<array_size; i++)
	{
		cout<<arra[i];
	}

	return 0;
}