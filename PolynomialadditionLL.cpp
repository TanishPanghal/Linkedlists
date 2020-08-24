#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

class Sll
{
	public:
		class node
		{
			public:
				int coeff;     
				int pow;       
				node *next;
		}*first,*last,*temp,*temp1;
		
		void insert(int,int);
		void display();
		void sum(Sll);
		Sll()
		{
			first=last=NULL;
		}
};

void Sll::display()
{	
	temp=first;
	while(temp!=NULL)
	{
	
		if(temp->coeff>0)
		{
		    if(temp->coeff==0)
		    {
		    	temp=temp->next;
			}
			
			if(temp->pow==0)
			{
				cout<<'+'<<temp->coeff;
			}
			else if(temp->pow==1)
			{
				cout<<'+'<<temp->coeff<<"x";
			}
		    else
		    {
		    	cout<<'+'<<temp->coeff<<"x^"<<temp->pow;
			}
			
		}
		else
		{
			if(temp->coeff==0)
			{
				temp=temp->next;
			}
			if(temp->pow==0)
			{
				cout<<temp->coeff;
			}
			else if(temp->pow==1)
			{
				cout<<temp->coeff<<"x";
			}
			else
			{
				cout<<temp->coeff<<"x^"<<temp->pow;	
			}  
		}
		temp=temp->next;
	}
}

void Sll::sum(Sll ob1)
{
	int flag;
	ob1.temp1=ob1.first;
	while(ob1.temp1)
	{
		temp1=first;
		while(temp1)
		{
			if(temp1->pow == ob1.temp1->pow)
		    {
		    	temp1->coeff = temp1->coeff+ob1.temp1->coeff;
		    	flag=1;
		    	break;
		    }
		    else
		    {
		    	flag=0;
			}
			temp1=temp1->next;
		}
		if(flag==0)
		{
			insert(ob1.temp1->pow,ob1.temp1->coeff);
		}
		ob1.temp1=ob1.temp1->next;
	}
	cout<<"\nSum:";
	display();
}

void Sll::insert(int p,int c)
{
	temp=new node;
	temp->next=NULL;
	temp->pow=p;
	temp->coeff=c;
	if(first==NULL)
	    first=last=temp;
	else
	{    
	    last->next=temp;    
		last=temp;  
	}   
}

int main()
{
	Sll obj1,obj2;
	int a,b;
	char ch;
	cout<<"\n First Polynomial ";
	do
	{
		cout<<"\nEnter the power: ";
		cin>>a;
		cout<<"\nEnter the coefficient : ";
		cin>>b;
		obj1.insert(a,b);
		cout<<"\nWant to add more (y/n) : ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	obj1.display();
	cout<<"\n\n";
	cout<<"\nSecond Polynomial";
		do
	{
		cout<<"\nEnter the power:";
		cin>>a;
		cout<<"\nEnter the coefficient:";
		cin>>b;
		obj2.insert(a,b);
		cout<<"\nWant to add more (y/n):";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	obj2.display();
	obj1.sum(obj2);
	return 0;
}
