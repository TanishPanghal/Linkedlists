#include<iostream>
#include<stdio.h>

using namespace std;

struct Node
{
	int data;
	Node *next;
};


class Stack
{
    Node *top;
    
  public:

	Stack()
	{
		top = NULL;
	}
	void push()
	{
		int value;
		Node *ptr;
		
		cout<<"\nEnter the value : ";
		cin>>value;
		
		ptr = new Node;
		ptr->data = value;
		ptr->next = NULL;

		if(top==NULL)
			top=ptr;
		else
		{
			ptr->next=top;
			top=ptr;
		}

	}  


	void pop()
	{
		Node *temp;

		if(top==NULL)
			cout<<"\nStack is Empty";
		else
		{
			cout<<"\nDeleted element is : "<<top->data;
			temp=top;
			top=top->next;
			delete temp;
		}
    }


    void clear()
    {
    	Node *ptr1 = top;

    	while(ptr1 != NULL)
    	{
    		cout<<ptr1->data<<"->";
            Node *temp = ptr1->next;
            delete ptr1;
            ptr1 = temp;

    	}
        
    }
};


int main()
{
    Stack s;
    int ch;
    while(1)
    {
    	cout<<"\n1.PUSH\n2.POP\n3.CLEAR\n";
    	cin>>ch;
    	switch(ch)
    	{
          case 1:
                  s.push();
                  break;
          case 2:
                  s.pop();
                  break;
          case 3:
                  s.clear();
                  exit(0);
          default:
                  cout<<"\nEnter a valid choice";              
    	}
    }
	return 0;
}
