// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void merge(float arr[],int start,int mid,int end )
{
    float team[100];
    int k=0,i=start,j=mid+1;
    for(;i<=mid&&j<=end;)
    {
        if(arr[i]>arr[j])
        {
            team[k++]=arr[j++];
        }
        else
        {
            team[k++]=arr[i++];

        }
        
    }
    for(;i<=mid;i++)
        {
            team[k++]=arr[i];
        }
        for(;j<=end;j++)
        {
            team[k++]=arr[j];
        }
        
        for(int z=0;z<k;z++)
        {
            arr[start+z]=team[z];
        }
}
void Mergesort(float arrar[],int start,int end)
{
    int mid;
    if(start==end)
    {
        return;
    }
    mid=(start+end)*0.5;
    Mergesort(arrar,start,mid);
    Mergesort(arrar,mid+1,end);
    merge(arrar,start,mid,end);
}
int main() {
    float arra[100];
    int array_size;
    cout<<"Enter the array size: ";
    cin>>array_size;
    cout<<"Enter the array: \n";
    for(int i=0;i<array_size;i++)
    {
        cin>>arra[i];
    }
    Mergesort(arra,0,array_size-1);
    for(int i=0;i<array_size;i++)
    {
        cout<<arra[i];
    }
    
    return 0;
}