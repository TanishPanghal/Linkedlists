#include <iostream>

using namespace std;

class CDll
{
	struct node
	{
		int data;
		struct node *prev, *next;
	};
	struct node *temp, *ptr, *tail;

  public:
	CDll()
	{
		tail = NULL;
	}
	~CDll()
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
	void insertinend();
	void insertinbegin();
	void insertinbet();
	void deleteatend();
	void deleteatbegin();
	void deleteinbet();
	void display();
};
bool CDll::is_empty()
{
	if (tail == NULL)
		return true;
	else
		return false;
}
void CDll::create()
{
	char ch = 'y';
	do
	{
		insertinend();
		cout << "Want to enter more nodes ? (y/n) : ";
		cin >> ch;
	} while (ch == 'y');
}
void CDll::display()
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
			cout << " «-» " << ptr->data;
		} while (ptr != tail);
		cout << " «-»...";
	}
	cout << endl;
}
void CDll::insertinend()
{
	temp = new node;
	cout << "\nEnter the node data : ";
	cin >> temp->data;
	if (is_empty())
	{
		tail = temp;
		tail->prev = tail;
		tail->next = tail;
	}
	else
	{
		temp->next = tail->next;
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	cout << "Inserted!" << endl;
}
void CDll::insertinbegin()
{
	temp = new node;
	cout << "\nEnter the node data : ";
	cin >> temp->data;
	if (is_empty())
	{
		tail = temp;
		tail->prev = tail;
		tail->next = tail;
	}
	else
	{
		temp->next = tail->next;
		temp->prev = tail;
		tail->next->prev = temp;
		tail->next = temp;
	}
	cout << "Inserted!" << endl;
}
void CDll::insertinbet()
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
				temp->prev = ptr;
				ptr->next->prev = temp;
				ptr->next = temp;
				cout << "Inserted!" << endl;
			}
		}
	}
}
void CDll::deleteatend()
{
	if (!is_empty())
	{
		temp = tail->prev;
		if (temp == tail)
		{
			delete temp;
			tail=NULL;
		}
		else
		{
			temp->next = tail->next;
			tail->next->prev = temp;
			delete tail;
			tail = temp;
		}
		cout << "\nDeleted one node from end!" << endl;
	}
}
void CDll::deleteatbegin()
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
			temp->next->prev = tail;
			tail->next = temp->next;
			delete temp;
		}
		cout << "\nDeleted one node from beginning!" << endl;
	}
}
void CDll::deleteinbet()
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
			temp = ptr->next;
			if (temp == tail)
				deleteatend();
			else
			{
				ptr->next = temp->next;
				temp->next->prev = ptr;
				delete temp;
				cout << "\nDeleted from location : " << loc << "!" << endl;
			}
		}
	}
}
void CDll::count()
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
void CDll::search()
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
int main()
{
	int choice;
	char ch;
	CDll list;
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
		cout<<"\n10. Display";
		cout<<"\n11. Exit" << endl;
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
			list.display();
			break;
		case 11:
			exit(0);
		}
		cout << "\nWant to operate more? (y/n) ";
		cin >> ch;
	} while (ch == 'y');
}

