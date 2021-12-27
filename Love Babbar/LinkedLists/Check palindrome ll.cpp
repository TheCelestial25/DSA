Node* reverse(Node* head) {
    Node* ptr = head;
    Node* prev = NULL;
    while(ptr) {
        Node* temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    return prev;
}
bool isPalindrome(Node *head)
{
    Node* slow = head, *fast = head, *prev = NULL;
    while(fast) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;
    }
    Node* rev = reverse(slow);
    while(rev and head) {
        if(rev->data != head->data) return false;
        rev = rev->next;
        head = head->next;
    }
    prev->next = reverse(slow);
    return true;
}