# include <iostream>
# include <stack>
# include <map>
# include "linkedList.h"

using namespace std;

Node* getNode(int x) 
{
	Node *newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

linkedList::linkedList() 
{
	head = NULL;
}
	
void linkedList::insertAtBeginning(int x) 
{
	Node *newNode = getNode(x);
	if(head) {
		newNode->next = head;
	}
	head = newNode;
}
	
void linkedList::insertAtEnd(int x) 
{
	Node *newNode = getNode(x);
	Node *temp;
	temp = head;
	if(head == NULL) {
		head = newNode;
		return;
	}		
	while(temp->next) {
		temp = temp->next;
	}
	temp->next = newNode;
}
	
void linkedList::display()
{
	Node *temp = head;
	if(head == NULL) {
		cout << "LIST EMPTY.\n";
		return;
	}
	while(temp->next) {
		cout << temp->data << " --> ";
		temp = temp->next;
	}
	cout << temp->data << " --|\\\n";
}

void linkedList::reverseUtil(Node *curr, Node *prev, Node **head)
{
	if(!curr->next) {
		*head = curr;
		curr->next = prev;
		return;
	}
	Node *nexte = curr->next;
	curr->next = prev;
	reverseUtil(nexte, curr, head);
}

void linkedList::reverseList()
{
	if(!head) return;
	reverseUtil(head, NULL, &head);
	/*
	 * Iterative method
	 */
	/*
	Node *curr, *nexte;
	curr = nexte = head;
	nexte = curr->next;
	while(nexte) {
		if(curr == head) {
			curr->next = NULL;
		}
		Node *saver = nexte->next;
		nexte->next = curr;

		curr = nexte;
		nexte = saver;
	}
	head = curr;
	*/
}

void linkedList::insertAtKthePosition(int position, int val)
{
	int k = 1;
	if (position <= k) {
		insertAtBeginning(val);
	} else {
		Node *temp = head;
		Node *prev = NULL;
		while(temp && k < position) {
			prev = temp;
			temp = temp->next;
			k++;
		}
		Node *newNode = getNode(val);
		prev->next = newNode;
		newNode->next = temp;
	}
}

Node* linkedList::getMiddleNode()
{
	Node *snail, *tortoise;
	snail = tortoise = head;
	int turn = 1;
	while(tortoise) {
		if(turn  == 1) {
			tortoise = tortoise->next;
		} else {
			tortoise = tortoise->next;
			snail = snail->next;
		}
		turn = 1 - turn;
	}
	return snail;
}

bool linkedList::isEmpty()
{
	return head == NULL;
}
void linkedList::deleteSpecified(int val)
{
	Node *temp = head;
	Node *prev = NULL;
	if(isEmpty()) {
		return;
	}
	while(temp) {
		if(temp->data == val) {
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if(temp == head) {
		head = head->next;
	} else if(temp) {
		prev->next = temp->next;
	} else {
		cout << "INVALID DATA.\n";
	}
}

void linkedList::removeDuplicates()
{
	Node *origin = head;
	while(head) {
		while(head->next && (head->next->data == head->data)) {
			head->next = head->next->next;
		}
		head = head->next;
	}
	head = origin;
}

bool linkedList::deleteList()
{
	Node *temp = head;
	while(head) {
		temp = head;
		head = head->next;
		delete temp;
	}
	if(isEmpty()) return true;
	else return false;
}

void linkedList::removeAllDuplicates()
{
	if(isEmpty()) return;
	map<int, int> mp;
	map<int, int>::iterator i;
	while(head) {
		i = mp.find(head->data);
		if(i == mp.end()) {
			mp.insert(make_pair(head->data, 1));
		} else {
			i->second++;
		}
		head = head->next;
	}
	if(!deleteList()) cout << "Error.\n";
	for(i = mp.begin(); i != mp.end(); i++) {
		if(i->second == 1) {
			insertAtEnd(i->first);
		} else continue;
	}
	
}

void linkedList::reverseKelemsAtaTime(int k)
{
	Node *current, *prev, *temp;
	prev = NULL, current = head;
	stack<Node*> st;
	if(isEmpty() || !k) return;
	while(current) {
		int count = 0;
		while(count < k && current) {
			count++;
			st.push(current);
			current = current->next;
		}
		while(!st.empty()) {
			temp = st.top();
			st.pop();
			if(!prev) {
				prev = temp;
				head = prev;
			} else {
				prev->next = temp;
				prev = prev->next;
			}
		}
	}
	prev->next = NULL;
}

void linkedList::rotateList(int B)
{
	if(isEmpty()) return;
	Node *current = head;
	int len = 1;
	while(current->next) {
		current = current->next;
		len++;
	}
	B = B % len;
	if(B) {
		current->next = head;
		current = head;
		len -= (B + 1);
		while(len) {
			current = current->next;
			len--;
		}
		head = current->next;
		current->next = NULL;
	}
}

void linkedList::insertionSort()
{
	if(isEmpty()) return;
	Node *currprev, *curr, *prev, *temp;
	temp = head;
	currprev = head;
	curr = head->next;
	while(curr) {
		prev = NULL;
		temp = head;
		if(currprev->data > curr->data) {
			while(temp->data < curr->data) {
				prev = temp;
				temp = temp->next;
			}
			if(temp != curr) {
				if(prev) 
					prev->next = curr;
				else {
					head = curr;
				}
				currprev->next = curr->next;
				curr->next = temp;
				curr = currprev->next;
			}
		} else {
			currprev = curr;
			curr = curr->next;
		}
	}
}