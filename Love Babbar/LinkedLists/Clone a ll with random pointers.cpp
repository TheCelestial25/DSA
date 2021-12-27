Node *copyList(Node *head)
{
    Node* ptr = head;
    while(ptr) {
        Node* temp = new Node(ptr->data);
        temp->next = ptr->next;
        ptr->next = temp;
        ptr = temp->next;
    }
    ptr = head;
    while(ptr) {
        ptr->next->random = ptr->random ? ptr->random->next : ptr->random;
        ptr = ptr->next ? ptr->next->next : ptr->next;
    }
    Node* res = head->next;
    ptr = head->next;
    while(ptr and head) {
        head->next = head->next->next;
        ptr->next = ptr->next ? ptr->next->next : ptr->next;
        head = head->next;
        ptr = ptr->next;
    }
    return res;
}