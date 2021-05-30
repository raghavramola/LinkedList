#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int key;
	Node* next;
	Node(int x)
	{
		key = x;
		next = NULL;
	}
};
void insertatend(Node** head,Node** tail,int num)
{
	Node* temp = new Node(num);
	if((*head)==NULL)
	{
		(*head) = (*tail)= temp;
	
	}
	else
	{
		(*tail) ->next = temp;
		(*tail) = temp;
	}
}
void deletefrombegining(Node** head,Node** tail)
{
	
	Node* temp = (*head);
	int x = temp->key;
	cout<<"Node with key "<<x<<" deleted\n";
	if((*head)==(*tail))
	{
		(*head) = (*tail) = NULL;
		
	}
	else
	{
		(*head) = temp->next;
	}
	delete temp;
}
void printlist(Node* head)
{
	cout<<"Elements in Linked List are\n";
	while(head!=NULL)
	{
		cout<<head->key<<"->";
		head = head->next;
	}
	cout<<"\n";
}
int main()
{
	Node* head=NULL;
	Node* tail=NULL;
	char ch;
	do
	{
		int n;
		cout<<"Press 1 - Enter data in Linked List\nPress 2 - Delete from Linked List\nPress 3 - Print the Linked List\n";
		cin>>n;
		switch(n)
		{
			case 1:
				int num;
				cout<<"Enter Data to Insert\n";
				cin>>num;
				insertatend(&(head),&(tail),num);
				break;
			
			case 2:
				if(head==NULL)
				{
					cout<<"List is empty ,nothing to delete\n";
				}
				else
				{
					deletefrombegining(&head,&tail);
				}
				break;
			
			case 3:
				if(head==NULL)
				{
					cout<<"List is empty\n";
				}
				
				else
				{
					printlist(head);
				}
				break;
			
			default :
				cout<<"wrong choice\n";		
		}
		cout<<"Press y to repeat\n";
		cin>>ch;
		cin.ignore();
	}while(ch=='y');
	return 0;
}
