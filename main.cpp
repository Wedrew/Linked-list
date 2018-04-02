#include<iostream>
using namespace std;

class NumberList
{
private:
   struct ListNode
   {
      double value;           
      struct ListNode *next;  
   }; 
   ListNode *head;           

public:
   NumberList()
      {
		  head = new ListNode;  
		  head->value = 0;
		  head->next = NULL;
	  }
   void appendNode(double);
   void InsertionSort();
   void displayList() const;
};

void NumberList::appendNode(double num)
{
	ListNode *newNode; //To point to a new node
	ListNode *nodePtr; //To move through the list

	// Allocate a new node and store num there
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	//If there are no nodes in the list make newNode the first node.
	if(!head)
		head = newNode;
	else
	{
		//Initialize nodePtr to head of list
		nodePtr = head;

		//Find the last node in the list
		while(nodePtr->next)
			nodePtr = nodePtr->next;

		//Insert newNode as last node
		nodePtr->next = newNode;
	}
}  

void NumberList::displayList() const
{
	ListNode *nodePtr;
	nodePtr = head;
	while(nodePtr)
	{
		cout << nodePtr->value << endl;
		nodePtr = nodePtr->next;
	}
}

void NumberList::InsertionSort()
{
	NumberList temp;   
	ListNode *add; 

	ListNode *addNext;
	ListNode *insert;

	add = head->next; //The first node to be sorted is the one after the head node (which has the value 0)

	while (add->next)
	{
		addNext = add->next;
		insert = temp.head;

		while(insert->next)
		{
			if(insert->value < add->value)
			{
                break;
            }
            insert = insert->next;		
        }
		add->next = insert->next;
		insert->next = add;
		add = addNext;
		
	}
	delete head;
    head = temp.head;
    temp.head = NULL;
}

int main()
{
	NumberList example;
	example.appendNode(5);
	example.appendNode(2);
	example.appendNode(4);
	example.appendNode(7);
	example.appendNode(3);
	example.appendNode(1);
	example.appendNode(6);

	cout <<"In original order: "<<endl;
	example.displayList();
	cout <<"\n\nIn sorted order: "<<endl;
	example.InsertionSort();
	example.displayList();

	return 0;  
}