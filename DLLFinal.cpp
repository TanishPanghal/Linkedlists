#include<iostream>
#include<stdio.h>

using namespace std;
class node
{
	public:
		int data;
		node *prev;
		node *next;
};
class Dll
{
	public:
		node *first,*tail,*temp,*temp1;
		Dll()
		{
			first=tail=NULL;
		}
		~Dll()
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
		void delAtEnd();
		void delAtBeg();
		void delInBet();
		int search(int);
		void reverse();
		void display();
};
void Dll::insertAtBeg(int el)
{
	temp=new node();
	temp->next=temp->prev=NULL;
	temp->data=el;
	if(first==NULL)
	{
		first=tail=temp;
	}
	else
	{
		temp->next=first;
		first->prev=temp;
		first=temp;
	}
	display();
}
void Dll::insertAtEnd(int el)
{
	temp=new node();
	temp->next=temp->prev=NULL;
	temp->data=el;
	if(first==NULL)
	{
		first=tail=temp;
	}
	else
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
	display();
}
void Dll::insertInBet(int el)
{
	temp=new node();
	temp->next=temp->prev=NULL;
	temp->data=el;
	int pos;
	cout<<"\n Enter the position of the node : ";
	cin>>pos;
	if(first==NULL)
	{
		first=tail=temp;
	}
	else
	{
		temp1=first;
		for(int i=1;i<pos-1;i++)
		{
			temp1=temp1->next;
			if(temp1==tail&&i==(pos-2))
			{
				tail->next=temp;
				temp->prev=tail;
				tail=temp;
				break;
			}
			if(temp1==NULL)
			{
				cout<<"\nNo such position found";
				exit(0);
			}
		}
		temp->next=temp1->next;
		temp1->next->prev=temp;
		temp->prev=temp1;
		temp1->next=temp;
	}
	display();
}

void Dll::delAtBeg()
{
	temp=first;
	first=first->next;
	first->prev=NULL;
	delete temp;
}
void Dll::delAtEnd()
{
	temp=tail;
	tail=tail->prev;
	delete temp;
	tail->next=NULL;
	display();
}
void Dll::delInBet()
{	display();
	int pos;
	cout<<"\n Enter the position of the node : ";
	cin>>pos;
	temp1=first;
	for(int i=1;i<pos-1;i++)
	{
		temp1=temp1->next;
	}
	temp=temp1->next;
	temp1->next=temp1->next->next;
	delete temp;
	display();
}

int Dll::search(int el)
{
	temp=first;
	while(temp!=NULL)
	{
		if(temp->data==el)
		    return 1;  
		temp=temp->next;	  
	}
	return 0;
}

void Dll::reverse()
{
	temp1=tail;
	temp=first;
	while(temp!=temp1)
	{
		while(temp->next!=temp1)
		{
			temp=temp->next;
		}
		temp1->next=temp;
		temp1=temp;
		temp=first;
	}
	temp=first;
	first=tail;
	tail=temp;
	tail->next=NULL;
	display();
}

void Dll::display()
{
	temp=first;
	while(temp!=NULL)
	{
		cout<<" "<<temp->data;
		temp=temp->next;
	}
}

int main()
{
	int ch,e,inf=0;
	Dll ob;
		do
		{
		
			cout<<"Insert at begining";
			cout<<"\nInsert at end";
			cout<<"\nInsert in between";
			cout<<"\nDelete in begining";
			cout<<"\nDelete at end";
			cout<<"\nDelete in between";
			cout<<"\nSearch";
			cout<<"\nReverse";
			cout<<"\nOutput";
			cout<<"\nEnter your choice(0 to exit) : ";
			cin>>ch;
			
			switch(ch)
			{
				case 1: cout<<"\nEnter the data : ";
				        cin>>e;
				        ob.insertAtBeg(e);
				        break;
				case 2: cout<<"\nEnter the data : ";
				        cin>>e;
				        ob.insertAtEnd(e);
				        break;
				case 3: cout<<"\nEnter the data : ";
				        cin>>e;
				        ob.insertInBet(e);
				        break;
				case 4: ob.delAtBeg();
				        break;
				case 5: ob.delAtEnd();
				        break;
				case 6: ob.delInBet();
				        break;	
				case 7: cout<<"\nEnter the element for searching:";
				        cin>>e;
				        inf=ob.search(e);
				        if(inf==1)
				              cout<<"\nElement found";
				        else
						      cout<<"\nNot found";      
				        break;
				case 8: ob.reverse();
				        break;	
				case 9: ob.display();
				        break;
				case 0: exit(0);
				default: "\nWrong input";
				         break;														        
			}
		}while(ch!=0);
	return 0;

	}
	

