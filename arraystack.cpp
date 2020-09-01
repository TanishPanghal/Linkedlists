//stack using array
#include <iostream>
#include <stdio.h>

using namespace std;

#define MAX 10

template <class T>

class Stack
{
T arr[MAX];

public:

     T item,r;
     int top;

     Stack()
     {
     	top=-1;
     } 	

     void push(T a)
     {
     	if(top==MAX)
     		cout<<"\nStack is full";
     	else
     	    arr[++top] = a;
     }

     T pop()
     {
     	if(top==-1)
     	{
     		cout<<"\nStack is empty";
     	
     	}
     	else
     		return arr[top--];
     }

     void clear()
     {
         while(top!=-1)
         {
         	cout<<arr[top--]<<"->";
         }
         cout<<"NULL\n";

         
     }
};


int main()
{
    Stack <int>s;
    int ch;
    while(1)
    {
    	cout<<"\n1.PUSH";
		cout<<"\n2.POP";
		cout<<"\n3.CLEAR\n";
    	cin>>ch;
    	switch(ch)
    	{
          case 1:
                  cout<<"\nPush an element: ";
                  cin>>s.item;
                  s.push(s.item);
                  break;
          case 2:
                  s.r = s.pop();
                  cout<<"\nPopped element is : "<<s.r;
                  break;
          case 3:
                  s.clear();
                  exit(0);
          default:
                  cout<<"\nwrong choice!";              
    	}
    }
	return 0;
}
