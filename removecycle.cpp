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
node* removecycle(node*&head)
{
	node*fast=head;
	node*slow=head;
	while(fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow)
		{
			slow=head;
			slow=slow->next;
			fast=fast->next;
			if(slow==fast)
			{
				fast->next=NULL;
			}
		}
	}
	return head;
}
int main ()
{
	node*head=NULL;
	cin>>head;
	cout<<head;
	cout<<removecycle(head);
	
}
