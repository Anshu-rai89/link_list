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
	cout<<"inserting at head "<<data<<endl;
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
void getdata(node*&head,int k)
{
	int data,c=0;
	while(c<k)
	{ cin>>data;
		insertattail(head,data);
		c++;
	}
	return;
}
/*istream & operator >>(istream& is,node*&head)
{
	getdata(head);
	return is;
}*/
ostream& operator <<(ostream& os,node*&head)
{
	print(head);
	return os;
}
void even(node*&head)
{ node*currunt=head;
	node*evenhead=NULL;
	node*oddhead=NULL;
	while(currunt!=NULL)
	{
	
	if(currunt->data%2==0)
	{
		insertattail(evenhead,currunt->data);
	}
	else
	{
		insertattail(oddhead,currunt->data);
	}
	currunt=currunt->next;
}
//cout<<oddhead;
node*ptr;
while(oddhead->next!=NULL)
{
	ptr=oddhead;
	oddhead=oddhead->next;
}
ptr->next=evenhead;
cout<<oddhead;

	return;
}
int main ()
{
	node*head=NULL;
	int n;
	cin>>n;
	getdata(head,n);
	//cout<<head;
	even(head);
	
}
