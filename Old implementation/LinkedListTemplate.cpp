#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node {
	int val;
	Node* next;
};

Node* createList(int n) {
	Node* curr = new Node();
	Node* head = curr;
	int i=0;
	
	int a[n] = {
		2,3,4,7,31,5,47,6
	};
	while(++i < n) {
		// curr->val = i;
		curr->val = a[i-1];
		curr->next = new Node();
		curr = curr->next;
	}
	curr->next = NULL;
	curr->val = n;
	curr->val = a[n-1];
	return head;
}

void printList(Node* head) {
	while(head) {
		cout << head->val << "->";
		head = head->next;
	}
	cout << "NULL" << endl;
}

Node* reverseList(Node* head) {
	Node* curr = head;
	Node* prev = NULL;
	while(curr) {
		Node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

Node* reverseSubList(Node* head, int k) {
	Node* curr = head;
	Node* prev = NULL;
	while(curr && k--) {
		Node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

bool isPalindrome(Node* head) {
	int n=0;
	Node* ptr1 = head;
	while(ptr1) {
		n++;
		ptr1 = ptr1->next;
	}
	ptr1 = head;
	for(int i=0; i<n/2; i++) ptr1 = ptr1->next;
	if(n%2 == 1) ptr1 = ptr1->next;
	Node* ptr2 = reverseSubList(head, n/2);
	for(int i=0; i<n/2; i++) {
		if(ptr1->val != ptr2->val) return 0;
		else {
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}
	return 1;
}

Node* KReverseList(Node* head, int k) {
	Node* curr = head;
	Node* prev = NULL;
	Node* next = NULL;
	int count = 0;
	while(curr && count++ < k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	if(next) head->next = KReverseList(next, k);
	return prev;
}

Node* partition(Node* head, int x) {
	if (!head) return NULL;
    Node *curr = head;

    Node *start = new Node(); // list of nodes greater than x
    Node *tail = start;

    Node *newHead = new Node();
    newHead->next = head;
    Node *pre = newHead; // previous node, we need it for removing

    while (curr) {
        if (curr->val >= x) {
            pre->next = curr->next; // remove from our list
            tail->next = curr;      // add to list of nodes greater than x
            tail = tail->next;
            curr = curr->next;
            tail->next = NULL;
        } else
            pre = curr, curr = curr->next;
    }
    pre->next = start->next;
    return newHead->next;
}

void InsertInSortedList(Node* &head, Node* element) {
	if(head==NULL || head->val >= element->val) {
		element->next = head;
		head = element;
		return;
	}
	Node* ptr = head;
	while(ptr->next && ptr->next->val < element->val) {
		ptr = ptr->next;
	}
	element->next = ptr->next;
	ptr->next = element;
}

Node* InsertionSort(Node* head) {	
	Node* res = NULL;
	Node* temp = head;
	while(temp) {
		Node* next = temp->next;
		InsertInSortedList(res, temp);
		temp = next;
	}
	return res;
}

Node* mergeSortedLists(Node* l1, Node* l2) {
	if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
	Node* p = new Node();
	Node* res = new Node();
	if(l1->val < l2->val) {
		res = l1;
		l1 = l1->next;
	}
	else {
		res = l2;
		l2 = l2->next;
	}
	p->next = res;
	while(l1 && l2) {
		if(l1->val < l2->val) {
			res->next = l1;
			l1 = l1->next;
		} else {
			res->next = l2;
			l2= l2->next;
		}
		res = res->next;
	}

	// Adding the rest
	if(l1) res->next = l1;
	else res->next = l2;
	return p->next;
}

Node* sortList(Node* head) {
	if(!head || !head->next) return head;
	Node* slow = head;
	Node* fast = head->next;
	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	fast = slow->next;
	slow->next = NULL;

	return mergeSortedLists(sortList(head), sortList(fast));
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* head = createList(8);
    printList(head);
    head = KReverseList(head,2);
    printList(head);
	return 0;
}