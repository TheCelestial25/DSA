Node* split(Node* head) {
    Node* fast = head;
    Node* slow = head;
    Node* prev = head;
    while(fast) {
        fast = fast->next;
        prev = slow;
        slow = slow->next;
        if(fast) fast = fast->next;
    }
    prev->next = NULL;
    return slow;
}
Node* merge(Node *h1, Node* h2) {
    Node *res, *head;
    if(h1->data <= h2->data) {
        res = h1;
        h1 = h1->next;
    }
    else {
        res = h2;
        h2 = h2->next;
    }
    head = res;
    while(h1 and h2) {
        if(h1->data <= h2->data) {
            res->next = h1;
            h1 = h1->next;
            res = res->next;
        } else {
            res->next = h2;
            h2 = h2->next;
            res = res->next;
        }
    }
    if(h1) res->next = h1;
    if(h2) res->next = h2;
    return head;
}
Node* mergeSortLL(Node* head) {
    if(!head->next) return head;
    Node* mid = split(head);
    head = mergeSortLL(head);
    mid = mergeSortLL(mid);
    Node* r = merge(head, mid);
    return r;
}
void printLL(Node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* mergeSort(Node* head) {
    if(!head or !head->next) return head;
    return mergeSortLL(head);
}