#include<iostream>
using namespace std;
class node
{ public :
	int data;
	node*next;
	
		node(int d)
		{
			data=d;
			next=NULL;
		}
		
}
;

void insertnode(node*&head,int data)
{
	node *n=new node(data);
	n->next=head;
	head=n;
}

void insertattail(node *&head,int data)
{
	if(head==NULL)
	{
		head=new node(data);
		return;
	}
	node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=new node(data);
}
int len(node *head)
{
	int l=0;
	while(head!=NULL)
	{
		head=head->next;
		l+=1;
	}
	return l;
}
void insertinmiddle(node*&head,int data,int p)
{
	if((head==NULL) ||(p==0))
	{
		insertnode(head,data);
		return;
	}
	else if(p>len(head))
	{
		insertattail(head,data);
		return;
	}
	else
	{ node *temp=head;
		int jump=1;
		while(jump<=p-1)
		{
			temp=temp->next;
			jump+=1;
		}
		node *n=new node(data);
		n->next=temp->next;
		temp->next=n;
	}
}
void deletathead(node *&head)
{
	if(head==NULL)
	{
		return;
	}
	node *temp=head;
	head=head->next;
	delete temp;
	return;
}
void deletattail(node *&head)
{
	node* prev;
	node *temp;
	prev=NULL;
	temp=head;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
		
	}
	prev->next=NULL;
	return;
}
void deletatmiddle(node *&head,int p)
{
	if((head==NULL) ||(p==0))
	{
		return;
	}
	else if(p>len(head))
	{
		deletattail(head);
		return;
	}
	else if(p==1)
	{
		deletathead(head);
	}
	else
	{
		node *prev=NULL;
		node *temp=head;
		int jump=1;
		while(jump<=p-1)
		{
			prev=temp;
			temp=temp->next;
			jump+=1;
		}
		prev->next=temp->next;
		delete temp;
	}
}
void print(node*head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}
int main()
{
	node *head=NULL;
	insertnode(head,1);
	insertnode(head,2);
	insertnode(head,3);
	print(head);
	int p;
	cout<<"enter p \n";
	cin>>p;
	insertinmiddle(head,6,p);
	print(head);
	insertattail(head,8);
	print(head);
	deletathead(head);
	deletattail(head);
	print(head);
	int q;
	cout<<"enter postion to be deleted \n";
	cin>>q;
	deletatmiddle(head,q);
	print(head);
	
}
