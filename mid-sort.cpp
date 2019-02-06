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
	void insertnode(node*&head,int data)
	{
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
	void getdata(node*head)
	{ int data;
		cin>>data;
		while(data!=-1)
		{
			head=head->next;
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
		b->next=merge(a,b->next);
	}
	else
	{
		c=a;
		a->next=merge(a->next,b);
	}
	return c;
}
node * mergesort(node*head)
{ if (head==NULL || head->next==NULL)
{
	return head;
}
	node* mid=midpoint(head);
	cout<<mid<<endl;
node*a=head;
cout<<a<<endl;
node*b=mid->next;
cout<<b<<endl;

mid->next=NULL;
a=mergesort(a);
b=mergesort(b);
node*c=merge(a,b);
return c;
}
	
		int main()
	{
		node*head=NULL;
		cin>>head;
		cout<<mergesort(head);
	}
