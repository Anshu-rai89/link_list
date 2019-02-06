#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void permutation(int *a,int size,int n)
{
	if(size==1) // Base case When only one element will be left we will print array
	{
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
		return;
	}
	// recursion part
	for(int i=0;i<size;i++) // iterating over array
	{
		permutation(a,size-1,n);// recursively calling fucntion so that we get all the combination
		if (size%2==0) // do swapping if you are on even position swap with starting array element
		{
			swap(&a[0],&a[size-1]);
		}
		else
		{
			swap(&a[i],&a[size-1]);// if you are on odd swap with the neighbour array element
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	permutation(a,n,n);
}
