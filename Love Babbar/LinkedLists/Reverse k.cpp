struct node *reverse (struct node *head, int k)
{ 
    // Complete this method
    if(!head) return NULL;
    node* p = NULL;
    node* r = head;
    int n = k;
    while(k-- and head != NULL) {
        node* temp = head->next;
        head->next = p;
        p = head;
        head = temp;
    }
    r->next = reverse(head, n);
    return p;
}