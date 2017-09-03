# include <iostream>
# include <cstdlib>
# include "linkedList.cpp"

using namespace std;

int displayMenu()
{
	cout << endl;
	cout << "1. Insert At Beginning.\n";
	cout << "2. Insert At End.\n";
	cout << "3. Display Linked List.\n";
	cout << "4. Reverse the Linked List.\n";
	cout << "5. Insert At position specified.\n";
	cout << "6. Find middle Node.\n";
	cout << "7. Delete the node with given data.\n";
	cout << "8. Remove Duplicates.\n";
	cout << "9. Remove those that appear more than once. (returns sorted list)\n";
	cout << "10. Reverse per k nodes.\n";
	cout << "11. Delete entire list.\n";
	cout << "12. Rotate List.\n";
	cout << "13. Use insertion sort on list.\n";
	int n;
	cin >> n;
	return n;
}

int main()
{
	linkedList listA;
	int ch;
	int x, y;
	while(1) {
		ch = displayMenu();
		switch(ch) {
			case 1: {
				cin >> x;
				listA.insertAtBeginning(x);
				break;
			}
			case 2: {
				cin >> x;
				listA.insertAtEnd(x);
				break;
			}
			case 3: {
				listA.display();
				break;
			}
			case 4: {
				listA.reverseList();
				break;
			}
			case 5: {
				cin >> x >> y;
				listA.insertAtKthePosition(x, y);
				break;
			}
			case 6: {
					Node *nodeX = listA.getMiddleNode();
					cout << "Middle node has data : " << nodeX->data << endl;
					break;
			}
			case 7: {
				cin >> x;
				listA.deleteSpecified(x);
				break;
			}
			case 8: {
				listA.removeDuplicates();
				break;
			}
			case 9: {
				listA.removeAllDuplicates();
				break;
			}
			case 10: {
				cin >> x;
				listA.reverseKelemsAtaTime(x);
				break;
			}
			case 11: {
				if(listA.deleteList()) cout << "List Deleted.\n";
				else cout << "List deletion failed.\n";
				break;
			}
			case 12: {
				cin >> x;
				listA.rotateList(x);
				break;
			}
			case 13: {
				listA.insertionSort();
				break;
			}
			default: exit(0);  
		} 
	}
	return 0;
}