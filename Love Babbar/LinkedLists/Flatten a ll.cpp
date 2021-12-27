Node* merge(Node *h1, Node* h2) {
    Node* temp = new Node(0);
    Node* res = temp;
    while(h1 and h2) {
        if(h1->data < h2->data) {
            temp->bottom = h1;
            temp = temp->bottom;
            h1 = h1->bottom;
        }
        else {
            temp->bottom = h2;
            temp = temp->bottom;
            h2 = h2->bottom;
        }
    }
    if(h1) temp->bottom = h1;
    else temp->bottom = h2;
    return res->bottom;
}

Node *flatten(Node *root)
{
   if(root == NULL or root->next == NULL) return root;
   root->next = flatten(root->next);
   root = merge(root, root->next);
   return root;
}