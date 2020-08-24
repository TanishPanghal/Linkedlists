  
#include <iostream>
using namespace std;
class CSll
{
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *temp, *ptr, *tail;

  public:
	CSll()
	{
		tail = NULL;
	}
	~CSll()
	{
		if (!is_empty())
		{
			cout << "\nDeallocating memory...\n";
			ptr = tail->next;
			tail->next = NULL;
			while (ptr != NULL)
			{
				temp = ptr->next;
				delete ptr;
				ptr = temp;
			}
		}
	}
	void create();
	bool is_empty();
	void count();
	void search();
	void reverse();
	void insertinbegin();
	void insertinend();
	void insertinbet();
	void deleteatend();
	void delete_at_begin();
	void deleteinbet();
	void display();
};
bool CSll::is_empty()
{
	if (tail == NULL)
		return true;
	else
		return false;}
void CSll::create()
{
	char ch = 'y';
	do
	{
		insertinend();
		cout << "Want to enter more nodes ? (y/n) : ";
		cin >> ch;
	} while (ch == 'y');
}
void CSll::display()
{
	cout << "\n\t";
	if (is_empty())
		cout << "Linked List is empty.";
	else
	{
		ptr = tail;
		do
		{
			ptr = ptr->next;
			cout << "-->" << ptr->data;
		} while (ptr != tail);
		cout << "-->...";
	}
	cout << endl;
}
void CSll::insertinend()
{
	temp = new node;
	cout << "\nEnter the node data : ";
	cin >> temp->data;
	if (is_empty())
	{
		tail = temp;
		tail->next = tail;
	}
	else
	{
		temp->next = tail->next;
		tail->next = temp;
		tail = temp;
	}
	cout << "Inserted!" << endl;
}
void CSll::insertinbegin()
{
	temp = new node;
	cout << "\nEnter the node data : ";
	cin >> temp->data;
	if (is_empty())
	{
		tail = temp;
		tail->next = tail;
	}
	else
	{
		temp->next = tail->next;
		tail->next = temp;
	}
	cout << "Inserted!" << endl;
}
void CSll::insertinbet()
{
	if (!is_empty())
	{
		temp = new node;
		int loc;
		cout << "\nEnter the location for new node : ";
		cin >> loc;
		if (loc == 1)
			insertinbegin();
		else
		{
			ptr = tail->next;
			for (int i = 1; i < loc - 1; i++)
			{
				ptr = ptr->next;
			}
			if (ptr == tail)
				insertinend();
			else
			{
				cout << "Enter the node data : ";
				cin >> temp->data;
				temp->next = ptr->next;
				ptr->next = temp;
				cout << "Inserted!" << endl;
			}
		}
	}
}
void CSll::deleteatend()
{
	if (!is_empty())
	{
		if (tail->next == tail)
		{
			delete tail;
			tail=NULL;
		}
		else
		{
			ptr = tail;
			do
			{
				ptr = ptr->next;
			} while (ptr->next != tail);
			ptr->next = tail->next;
			delete tail;
			tail = ptr;
		}
		cout << "\nDeleted one node from end!" << endl;
	}
}
void CSll::deleteatbegin()
{
	if (!is_empty())
	{
		temp = tail->next;
		if (tail->next == tail)
		{
			delete temp;
			tail = NULL;
		}
		else
		{
			tail->next = temp->next;
			delete temp;
		}
		cout << "\nDeleted one node from beginning!" << endl;
	}}
void CSll::deleteinbet()
{
	if (!is_empty())
	{
		int loc;
		cout << "\nEnter the location of node to delete : ";
		cin >> loc;
		if (loc == 1)
			deleteatbegin();
		else
		{
			ptr = tail->next;
			for (int i = 1; i < loc - 1; i++)
			{
				ptr = ptr->next;
			}
			if (ptr->next == tail)
				deleteatend();
			else
			{
				temp = ptr->next;
				ptr->next = temp->next;
				delete temp;
				cout << "\nDeleted from location : " << loc << "!" << endl;
			}
		}
	}
}
void CSll::count()
{
	if (!is_empty())
	{
		int count = 0;
		ptr = tail;
		do
		{
			ptr = ptr->next;
			++count;
		} while (ptr != tail);
		cout << "\nThere are " << count << " nodes in the list." << endl;
	}
	else
		display();
}
void CSll::search()
{
	if (!is_empty())
	{
		int n, count = 0, flag = 0;
		cout << "\nEnter the node data to be searched : ";
		cin >> n;
		ptr = tail;
		do
		{
			ptr = ptr->next;
			++count;
			if (ptr->data == n)
			{
				flag = 1;
				break;
			}
		} while (ptr != tail);
		if (flag == 1)
			cout << "Data found at location " << count << " in the list." << endl;
		else
			cout << "Data not found in the list.";
	}
	else
		display();
}
void CSll::reverse()
{
	if (!is_empty() && (tail->next != tail))
	{
		struct node *temp1 = new node;
		temp1 = tail->next;
		ptr = temp1->next;
		tail->next = NULL;
		tail = temp1;
		while (ptr != NULL)
		{
			temp = ptr;
			ptr = ptr->next;
			temp->next = temp1;
			temp1 = temp;
		}
		tail->next = temp1;
	}
	cout << "\nReversed!" << endl;
}
int main()
{
	int choice;
	char ch;
	CSll list;
	do
	{
		cout <<"\n1. Create";
		cout<<"\n2. Insert in Beginning";
		cout<<"\n3. Insert at End";
		cout<<"\n4. Insert in between";
		cout<<"\n5. Delete at Beginning";
		cout<<"\n6. Delete at End";
		cout<<"\n7. Delete in between";
		cout<<"\n8. Count the nodes";
		cout<<"\n9. Search";
		cout<<"\n10. Reverse the list";
		cout<<"\n11. Display";
		cout<<"\n12. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			list.create();
			list.display();
			break;
		case 2:
			list.insertinbegin();
			list.display();
			break;
		case 3:
			list.insertinend();
			list.display();
			break;
		case 4:
			list.insertinbet();
			list.display();
			break;
		case 5:
			list.deleteatbegin();
			list.display();
			break;
		case 6:
			list.deleteatend();
			list.display();
			break;
		case 7:
			list.deleteinbet();
			list.display();
			break;
		case 8:
			list.count();
			break;
		case 9:
			list.search();
			break;
		case 10:
			list.reverse();
			list.display();
			break;
		case 11:
			list.display();
			break;
		case 12:
			exit(0);
		}
		cout << "\nWant to operate more? (y/n) ";
		cin >> ch;
	} while (ch == 'y');
}
