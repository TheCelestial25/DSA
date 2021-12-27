// Should be done with Lomuto partitioning
ListNode* partition(ListNode* start, ListNode* end) {
    if(start==end) return start;
    int pivot = end->val;
    ListNode *i = start, *ret = start;
    for(ListNode* j = start; j and j != end; j = j->next) {
        if(j->val <= pivot) {
            swap(i, j);
            ret = i;
            i = i->next;
        }
    }
    swap(i, end);
    return ret;
}
void swap(ListNode* a, ListNode* b) {
    int t = a->val;
    a->val = b->val;
    b->val = t;
}
void quickSort(ListNode* head, ListNode* tail) {
    if(!head or head == tail) return;
    ListNode* pivot = partition(head, tail);
    // cout << head->val << " " << pivot->val << " " << tail->val << endl;
    if(pivot != tail) quickSort(head, pivot);
    quickSort(pivot->next, tail);
}
ListNode* sortList(ListNode* head) {
    if(!head or !head->next) return head;
    ListNode* tail = head;
    while(tail->next != NULL) tail = tail->next;
    quickSort(head, tail);
    return head;
}