Node* reverseDLL(Node * head)
{
    Node* prev = NULL;
    while(head) {
        prev = head;
        Node* temp = head->next;
        head->next = head->prev;
        head->prev = temp;
        head = temp;
    }
    return prev;
}