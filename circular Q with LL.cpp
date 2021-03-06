#include <iostream>
using namespace std; 
   
struct Node 
{ 
    int data; 
    struct Node* link; 
}; 
  
struct Queue 
{ 
    struct Node *front, *rear; 
}; 
  
void enQueue(Queue *q) 
{ 	int value;
	cout<<"\nEnter the value to be entered: ";	
			cin>>value;
    struct Node *temp = new Node; 
    temp->data = value; 
    if (q->front == NULL) 
        q->front = temp; 
    else
        q->rear->link = temp; 
  
    q->rear = temp; 
    q->rear->link = q->front; 
} 
  
int deQueue(Queue *q) 
{ 
    if (q->front == NULL) 
    { 
        cout<<"Queue is empty"; 
        return INT_MIN; 
    } 
  
    // If this is the last node to be deleted 
    int value; // Value to be dequeued 
    if (q->front == q->rear) 
    { 
        value = q->front->data; 
        delete(q->front); 
        q->front = NULL; 
        q->rear = NULL; 
    } 
    else  // There are more than one nodes 
    { 
        struct Node *temp = q->front; 
        value = temp->data; 
        q->front = q->front->link; 
        q->rear->link= q->front; 
        delete(temp); 
    } 
  
    return value ; 
} 
  
void displayQueue(struct Queue *q) 
{ 
    struct Node *temp = q->front; 
    cout<<"\nElements in Circular Queue are: "; 
    while (temp->link != q->front) 
    { 
        cout<<temp->data<<" "; 
        temp = temp->link; 
    } 
    cout<<temp->data; 
} 

int main() 
{   
	 Queue *q = new Queue; 
    	q->front = q->rear = NULL; 
  
 		cout<<"\n1.Insert an element in the Queue?";	
		cout<<"\n2.Deletion?";	
		cout<<"\n3.Display?";	
		cout<<"\n4.EXIT?";	
	
   /*
    enQueue(q, 14); 
    enQueue(q, 22); 
    enQueue(q, 6); 
   
    displayQueue(q); 
  
    cout<<"\nDeleted value = "<<deQueue(q); 
    cout<<"\nDeleted value = "<<deQueue(q); 
  
    displayQueue(q); 
  
    enQueue(q, 9); 
    enQueue(q, 20); 
    displayQueue(q); 
    */
  	int ch;
  do{
  cout<<"\nEnter your choice: ";
  cin>>ch;
  	  	switch(ch)
		{
		
		case 1: 
			
			enQueue(q);
			break;
		case 2: 
			cout<<"T\nhe deleted value is: "<<deQueue(q);	
			break; 
		case 3:
    		displayQueue(q); 
			break;
		case 4:
			exit(0);
		}
  		
  }while(ch!=4);
   return 0;
} 
