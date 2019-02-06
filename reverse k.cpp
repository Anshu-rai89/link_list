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
node* mid(node*head)
{
	node*fast=head;
	node*slow=head;
	while(fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	head=slow;
	return head;
}

void input(node *&head,int n)
{int data,c=0;

while(c<n)
{ cin>>data;
	insertattail(head,data);
	c++;
	
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
/*istream& operator >>(istream &is,node * &head)
{
    input(head);
	return is;
}*/
ostream& operator <<(ostream &os,node *&head)
{
	print(head);
	return os;
}
int len(node*head)
{
	int l=0;
	while(head!=NULL)
	{
		head=head->next;
		l++;
	}
	return l;
}
node* reverse(node*&head)
{ 
if(head->next==NULL || head==NULL)
{
	return head;
	
}
node*smallhead=reverse(head->next);
node*c=head;
c->next->next=c;
c->next=NULL;
return smallhead;
}
bool palindrome(node*head)
{
	if(head==NULL)
	return false;
	node*temp=mid(head);
	
	node*temp1=reverse(temp->next);
//	cout<<temp1<<endl;
	temp->next=NULL;
//	cout<<temp;
	while(head!=temp)
	{
	  if(head->data!=temp1->data)
	  {
	  	return false;
	  	break;
		  }	
		  head=head->next;
		  temp1=temp1->next;
	}
	return true;
	
	
}
int main()
{
	node*head=NULL;
	int k;
	cin>>k;
	input(head,k);
	if(palindrome(head))
	{
		cout<<"true";
	}
	else
	cout<<"false";
	
}
