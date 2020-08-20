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
		void delAtEnd();
		void delAtBeg();
		void delInBet();
		int search(int);
		void reverse();
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
	cout<<"Enter the position:\n ";
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
				cout<<"Position not foound!";
				exit(0);
			}
		}
		temp->next=temp1->next;
		temp1->next=temp;
	}
	display();
}


void SLL::delAtBeg()
{
	temp=first;
	first=first->next;
	delete temp;
	display();	}


void SLL::delAtEnd()
{
	temp=first;
	while(temp->next!=last)
	{
		temp=temp->next;
	}
	delete last;
	last=temp;
	last->next=NULL;
	display();
}


void SLL::delInBet()
{
	int pos;
	cout<<"Enter the position of the node : \n";
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



int SLL::search(int el)
{	int c=0;
	temp=first;
	while(temp!=NULL)
	{
		if(temp->data==el)
		    {cout<<"found at "<<++c<<"  \n";
			return c;}  
		temp=temp->next;
		c+=1;	  
	}
	return 0;

}


void SLL::reverse()
{
	temp1=last;
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
	first=temp;
	first=last;
	last=temp;
	last->next=NULL;
	cout<<"Reversed successfully!\n";
	cout<<"Reversed list:\n";
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
	int ch,ch1,foundcheck=0;
	SLL ob;
do
		{
		cout<<"1.Insert in begining\n";
		cout<<"2.Insert at End\n";
		cout<<"3.Insert in between\n";
		cout<<"4.Dlete in begining\n";
		cout<<"5.Delete at end\n";
		cout<<"6.Delete in between\n";
		cout<<"7.Search\n";
		cout<<"8.Reverse\n";
		cout<<"9.Display\n";
		cout<<"Enter the choice!: ";
		cin>>ch;
		switch(ch)
		{	int e;
				case 1: cout<<"Enter the data : ";
				        cin>>e;
				        ob.insertAtBeg(e);
				        break;
				case 2: cout<<"Enter the data : ";
				        cin>>e;
				        ob.insertAtEnd(e);
				        break;
				case 3: cout<<"Enter the data : ";
				        cin>>e;
				        ob.insertInBet(e);
				        break;
				case 4: ob.delAtBeg();
				        break;
				case 5: ob.delAtEnd();
				        break;
				case 6: ob.delInBet();
				        break;	
				case 7: cout<<"Enter the element to be searched : ";
				        cin>>e;
				        foundcheck=ob.search(e);    
						if(foundcheck==0) {
							cout<<"Not found...";
						}
				        break;
				case 8: ob.reverse();
				        break;	
				case 9: ob.display();
				        break;
				case 0: exit(0);
				default: "Error wrong choice:";
				         break;														        
			}
		}while(ch!=0);
	return 0;
}
 
 
