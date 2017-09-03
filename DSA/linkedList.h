# ifndef LINKEDLIST_H
# define LINKEDLIST_H

struct Node {
	int data;
	Node *next;
};

Node* getNode(int);

class linkedList {
	Node *head;
public:
	linkedList();
	void insertAtBeginning(int);
	void insertAtEnd(int);
	void display();	
	void reverseList();
	void reverseUtil(Node*, Node*, Node**);
	void insertAtKthePosition(int, int);
	Node* getMiddleNode();
	void deleteSpecified(int);
	bool isEmpty();
	void removeDuplicates();
	void removeAllDuplicates();
	void reverseKelemsAtaTime(int);
	bool deleteList();
	void rotateList(int);
	void insertionSort();
};

# endif
