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
node* knode(node*head,int k)
{
	node*fast=head;
	node*slow=head;
	node*ptr=NULL;
	int i=1;
	while(i<k)
	{
		fast=fast->next;
		i++;
	}
	while(fast->next!=NULL)
	{ptr=slow;
		fast=fast->next;
		slow=slow->next;
	}
	node*n=head;
	node*temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	head=slow;
	temp->next=n;
	ptr->next=NULL;
	return head;
	
}
int main()
{
	node*head=NULL;
	int n,k;
	cin>>n;
	getdata(head,n);
	cin>>k;
	node*temp=knode(head,k);
	cout<<temp;
}
