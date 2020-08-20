#include<iostream>
#include<stdio.h>
using namespace std;


class node
{
	public:
		int data;
		node *next;
};


class SLL
{
	public:
		node *first,*last,*temp,*temp1;
		SLL()
		{
			first=last=NULL;
		}
		~SLL()
		{
			temp=first;
			while(first!=NULL)
			{
				temp=temp->next;
				delete first;
				first=temp;
			}
		}
		void insertAtBeg(int);
		void insertAtEnd(int);
		void insertInBet(int);
		void display();
};

void SLL::insertAtBeg(int dat)
{
	temp=new node();
	temp->next=NULL;
	temp->data=dat;
	if(first==NULL)
	{
		first=last=temp;
	}
	else
	{
		temp->next=first;
		first=temp;
	}
	display();
}


void SLL::insertAtEnd(int dat)
{
	temp=new node();
	temp->next=NULL;
	temp->data=dat;
	if(first==NULL)
	{
		first=last=temp;
	}
	else
	{
		last->next=temp;
		last=temp;
	}
	display();
}


void SLL::insertInBet(int dat)
{
	temp=new node();
	temp->next=NULL;
	temp->data=dat;
	int pos;
	cout<<"Enter the position: \n";
	cin>>pos;
	if(first==NULL)
	{
		first=last=temp;
	}
	else
	{
		temp1=first;
		for(int i=1;i<pos-1;i++)
		{
			temp1=temp1->next;
			if(temp1==last&&i==(pos-1))
			{
				last->next=temp;
				last=temp;
				break;
			}
			if(temp1==NULL)
			{
				cout<<"Cannot find this position...\n";
				exit(0);
			}
		}
		temp->next=temp1->next;
		temp1->next=temp;
	}
	display();
}
void SLL::display()
{
	temp=first;
	while(temp!=NULL)
	{
		cout<<" "<<temp->data<<" ";
		temp=temp->next;
	}
}

int main()
{
	int ch,ch1,flag=0;
	SLL ob;
do
		{cout<<"1. Insert in begining\n";
		cout<<" 2. Insert at End\n";
		cout<<" 3. Insert in between\n";
		cout<<" 4. Display\n";
		cout<<" Enter the choice : \n";
		cin>>ch;	
		switch(ch)
		{	int e;
			case 1: cout<<" Enter the data :\n";
				        cin>>e;
				        ob.insertAtBeg(e);
				        break;
			case 2: cout<<"\n Enter the data :\n";
				        cin>>e;
				        ob.insertAtEnd(e);
				        break;
			case 3: cout<<"\n Enter the data :\n";
				        cin>>e;
				        ob.insertInBet(e);
				        break;
			case 4: ob.display();
				        break;
				case 0: exit(0);
				default: "\n ENTER a valid choice:\n";
				         break;														        
			}
		}while(ch!=0);
	return 0;
}
 
	
