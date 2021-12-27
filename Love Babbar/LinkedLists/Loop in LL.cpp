void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    Node* slow = head;
    Node* fast = head;
    bool found = false;
    while(fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            found = true;
            break;
        }
    }
    if(!found) return;
    slow = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    while(fast->next != slow) fast = fast->next;
    fast->next = NULL;
}