Node* fun(Node* head, int &mx) {
    if(head->next == NULL) {
        mx = head->data;
        return head;
    }
    head->next = fun(head->next, mx);
    if(head->data >= mx) {
        mx = head->data;
        return head;
    }
    return head->next;
}
Node *compute(Node *head)
{
    int mx = 0;
    return fun(head, mx);
}