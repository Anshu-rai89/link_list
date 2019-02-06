#include<iostream>
using namespace std;
class node
{
	public :
		int data;
		node *next;
		node(int d)
		{
			data=d;
			next=NULL;
			
		}
		
};

void insertnode(node *&head,int data)
{
	node *n=new node(data);
	n->next=head;
	head=n;
}

void insertattail(node *&head,int data)
{ if(head==NULL)
{
	head=new node(data);
	return;
}
	node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
//	n->next=head;
	temp->next=new node (data);
	return;
}

void input(node *&head)
{int data;
cin>>data;
while(data!=-1)
{
	insertattail(head,data);
	cin>>data;
}
return;	
}
void print(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
	return;
}
istream& operator >>(istream &is,node * &head)
{
    input(head);
	return is;
}
ostream& operator <<(ostream &os,node *&head)
{
	print(head);
	return os;
}
void reverse(node*&head)
{
	node * p=NULL;
	node* c=head;
	node *n=NULL;
	while(c!=NULL)
	{
	
	 n=c->next;
	c->next=p;
	p=c;
	c=n;
}
head=p;
return;
}
node* reverserec(node*head)
{
	if((head->next==NULL)||(head==NULL))
	{ 
		return head;
	}

node*smallhead=	reverserec(head->next);
node*c=head;
c->next->next=c;
c->next=NULL;
return smallhead;
}
int main()
{
	node *head1=NULL;
	node *head2=NULL;
	cin>>head1>>head2;
	cout<<head1<<head2;
	reverse(head1);
	cout<<head1;
	head2=reverserec(head2);
	cout<<head2;
	
}
