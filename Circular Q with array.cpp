#include <iostream>
using namespace std; 
  
struct Queue 
{ 
    // Initialize front and rear 
    int rear, front; 
  
    // Circular Queue 
    int size; 
    int *arr; 
  
    Queue(int s) 
    { 
       front = rear = -1; 
       size = s; 
       arr = new int[s]; 
    } 
  
    void enQueue(); 
    int deQueue(); 
    void displayQueue(); 
}; 
  
  
	void Queue::enQueue() 
	{	 	int value;
	cout<<"\nEnter the value to be entered: ";	
	cin>>value;
    if ((front == 0 && rear == size-1) || 
            (rear == (front-1)%(size-1))) 
    { 
        cout<<"\nQueue overflow"; 
        return; 
    } 
  
    else if (front == -1) /* Insert First Element */
    { 
        front = rear = 0; 
        arr[rear] = value; 
    } 
  
    else if (rear == size-1 && front != 0) 
    { 
        rear = 0; 
        arr[rear] = value; 
    } 
  
    else
    { 
        rear++; 
        arr[rear] = value; 
    } 
} 
  
int Queue::deQueue() 
{ 
    if (front == -1) 
   	{ 
        cout<<"\nQueue is Empty"; 
        return INT_MIN; 
    } 
  
    int data = arr[front]; 
    arr[front] = -1; 
    if (front == rear) 
    { 
        front = -1; 
        rear = -1; 
    } 
    else if (front == size-1) 
        front = 0; 
    else
        front++; 
  
    return data; 
} 
  
// Function displaying the elements 
// of Circular Queue 
void Queue::displayQueue() 
{ 
    if (front == -1) 
    { 
        cout<<"\nQueue is Empty"; 
        return; 
    } 
    cout<<"\nElements in Circular Queue are: "; 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            cout<<arr[i]<<" "; 
    } 
    else
    { 
        for (int i = front; i < size; i++) 
             cout<<arr[i]<<" "; 
  
        for (int i = 0; i <= rear; i++) 
             cout<<arr[i]<<" "; 
    } 
} 
  
/* Driver of the program */
int main() 
{ 
    Queue q(5); 
  
    // Inserting elements in Circular Queue 
    
  
    // Display elements present in Circular Queue 
   /* q.displayQueue(); 
 
    q.displayQueue(); 
  
    q.enQueue(9); 
    q.enQueue(20); 
    q.enQueue(5); 
  
    q.displayQueue(); 
  
    q.enQueue(20); */
    	cout<<"\n1.Insert an element in the Queue?";	
		cout<<"\n2.Deletion?";	
		cout<<"\n3.Display?";	
		cout<<"\n4.EXIT?";	
    	int ch;
  do{
  cout<<"\nEnter your choice: ";
  cin>>ch;
  	  	switch(ch)
		{
		
		case 1: 
			
			q.enQueue();
			break;
		case 2: 
			cout<<"\nhe deleted value is: "<<q.deQueue();	
			break; 
		case 3:
    		q.displayQueue(); 
			break;
		case 4:
			exit(0);
		}
  		
  }while(ch!=4);
    return 0; 
} 
