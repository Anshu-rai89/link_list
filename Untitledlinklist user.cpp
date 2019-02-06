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
bool searchrec(node *head,int key)
{
	if(head==NULL)
	{
		return false;
	}
	if(head->data==key)
	{
		return true;
	}

	searchrec(head->next, key);
	
	//turn false;
}
bool searchitr(node *head,int key)
{
	
		while(head!=NULL)
		{
			if(head->data==key)
			{
				return true;
			}
			head=head->next;
}
return false;
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
int main ()
{
	node *head=NULL;
	input(head);
	print(head);
	int key;
	cout<<" enter number to be searche din link list\n";
	cin>>key;
	if(searchrec(head,key))
	{
		cout<<"present in Link List";
	}
	else
	{
		cout<<" Not Present in linl list";
	}
		cin>>key;
	if(searchitr(head,key))
	{
		cout<<"present in Link List";
	}
	else
	{
		cout<<" Not Present in linl list";
	}
	
	
}
