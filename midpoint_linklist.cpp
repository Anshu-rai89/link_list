#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node* next;
		node(int d)
		{
			data=d;
			next=NULL;
		}
};
node* midpoint(node*head)
{
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	head=slow;
	return head;
}
void insertnode(node*&head,int data)
{
//	node*temp=head;
	node*n=new node(data);
	n=head;
	head=n;
	return;
}
void insertattail(node*&head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node*temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new node(data);
	return;
}
void print(node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
	return;
}
void getdata(node*&head)
{
	int data;
	cin>>data;
	while(data!=-1)
	{
		insertattail(head,data);
		cin>>data;
	}
	return;
}
istream & operator >>(istream& is,node*&head)
{
	getdata(head);
	return is;
}
ostream& operator <<(ostream& os,node*&head)
{
	print(head);
	return os;
}
node* insertionsort(node*head)
{
	node*currunt=head;
	node*temp=currunt;
	head=head->next;
	while(head!=NULL)
	{
	  temp=currunt;
	  while(temp->next!=head)
	  {
	  	if(temp->data>head->data)
	  	{
	  		int temp1=temp->data;
	  		temp->data=head->data;
	  		head->data=temp1;
		  }
		  else
		  {
		  
		  temp=temp->next;
		  
		  }
	  }
	  head=head->next;
	}
	return head;
int knode(node*head,int k)
{
	node*fast=head;
	node*slow=head;
	int i=0;
	while(i<k)
	{
		fast=fast->next;
		i++;
	}
	while(fast->next!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	head=slow;
	return head->data;
}
node* merge(node*a,node*b)
{
	if(a==NULL)
	{
		return b;
	}
	else if(b==NULL)
	{
		return a;
	}
	node *c;
	if(a->data>b->data)
	{
		c=b;
		c->next=merge(a,b->next);
	}
	else
	{
		c=a;
		c->next=merge(a->next,b);
	}
//	cout<<" merge linl list"<<c<<endl;
	return c;
}
node * mergesort(node*head)
{ if (head==NULL || head->next==NULL)
{
	return head;
}
	node* mid=midpoint(head);
//	cout<<" mid is "<<mid<<endl;
node*a=head;
node*b=mid->next;

mid->next=NULL;
//cout<<" first linklist is "<<a<<endl;
//cout<<"second linklist is "<<b<<endl;
a=mergesort(a);
b=mergesort(b);
node*c=merge(a,b);
head=c;
return head;
}
int main()
{
	node* head=NULL;
//	cin>>head;
//	cout<<head;
//	node*temp=midpoint(head);
//	cout<<temp<<endl;
//	cout<<"enter kth node "<<endl;;
//	int k;
//	cin>>k;
//	cout<<knode(head,k);
//	cout<<"enter two sorted link list"<<endl;
//	node *head1=NULL;
	node*head2=NULL;
//	cin>>head1>>head2;
//	node * abc=merge(head1,head2);
//	cout<<abc;
//	cout<<"enter unsorted linklist"<<endl;
cin>>head;
//	cin>>head2;
	node* a=merge(head,head2);
	node*b=mergesort(head);
	cout<<b;
//getdata(head);
//print(head);
}
