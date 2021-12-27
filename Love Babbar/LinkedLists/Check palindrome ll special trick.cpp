bool fun(ListNode* right, ListNode* &left) {
    if(right == NULL) return true;
    bool ans = fun(right->next, left);
    ans = ans and right->val == left->val;
    left = left->next;
    return ans;
}
bool isPalindrome(ListNode *head)
{
    return fun(head, head);
}