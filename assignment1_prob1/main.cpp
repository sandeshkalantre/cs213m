#include <iostream>
#include "list.hpp"
#include "node.hpp"

using namespace std;

int main() {
	int N;
	cin >> N;

	Node* head = NULL;

	while (N--) {
		char op;
		cin >> op; // P = print, I = insert, D = remove, R = reverse, S = size, C = cycle size 
		switch (op) {
			case 'I': 
			{
				int val, pos;
				cin >> val >> pos;
				head = insert(head, val, pos);
				break;
			}
			case 'D':
			{
				int pos;
				cin >> pos;
				head = remove(head, pos);
				break;
			}
			case 'R':
			{
				head = reverse(head);
				break;
			}
			case 'S':
			{
				cout << size(head) << endl;
				break;
			}
			case 'P':
			{
				Node* tmp = head;
				while (tmp) {
					cout << tmp->getVal() << " ";
					tmp = tmp->getNext();
				}
				cout << '_' << endl;
				break;
			}
			case 'C':
			{
               cout<< cycle_size(head) << endl;
               break; 
            }
		}
	}
}





