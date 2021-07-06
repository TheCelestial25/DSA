// Implementation of binary search tree (BST) in C++ :

#include<bits/stdc++.h>
using namespace std;

struct treeNode{
    treeNode *left;
    treeNode *right;
    int data;
} ;
class bst{
    treeNode *root;
    public:
    bst(){
        root=NULL;
    }
    bool isempty() {
        if(root==NULL)
            return true;
    else 
            return false;
    }
    
    void insertNode(int item){
        treeNode *n = new treeNode;
        treeNode *parent = new treeNode;
        n->left = NULL;
        n->right = NULL;
        n->data = item;
        parent = NULL; // As the iterator becomes NULL, we need its parent
        if(isempty()) root = n;
        else {
        	treeNode *ptr = root;
        	while(ptr != NULL) {
        		parent = ptr;
        		if(item > ptr->data) ptr = ptr->right;
        		else ptr = ptr->left;
        	}
        	if(item < parent->data) parent->left = n;
        	else parent->right = n;
        }
    }
    
    void inOrderTraversal(){
        inOrderRec(root);
    }
    
    void inOrderRec(treeNode *ptr){
        if(ptr!=NULL){
            inOrderRec(ptr->left);
            cout<<"  "<<ptr->data<<"     ";
            inOrderRec(ptr->right);
        }
    }

    void preOrderTraversal(){
        preOrderRec(root);
    }
    
    void preOrderRec(treeNode *ptr){
        if(ptr!=NULL){
            cout<<"  "<<ptr->data<<"     ";
            preOrderRec(ptr->left);
            preOrderRec(ptr->right);
        }
    }

    void postOrderTraversal(){
        postOrderRec(root);
    }
    
    void postOrderRec(treeNode *ptr){
        if(ptr!=NULL){
            postOrderRec(ptr->left);
            postOrderRec(ptr->right);
            cout<<"  "<<ptr->data<<"     ";
        }
    }

    treeNode* searchNode(int val) {
    	if(root == NULL) return NULL;
    	treeNode* ptr = root;
    	while(ptr != NULL and ptr->data != val) {
    		if(val > ptr->data) ptr = ptr->right;
    		else ptr = ptr->left;
    	}
    	if(ptr != NULL and ptr->data == val) return ptr;
    	else return NULL;
    }

    treeNode* nextGreater(int val) {
    	treeNode *r = searchNode(val);
    	if(r == NULL) return NULL;
    	if(r->right != NULL) { // right subtree exists
    		r = r->right;
    		while(r->left) r = r->left;
    		return r;
    	} else { // find parent of parent
    		treeNode *parent = new treeNode();
    		treeNode *ptr = new treeNode();
    		ptr = root;
    		// Here we return the last node greater than our required node
    		while(ptr != r) {
    			if(ptr->data < val) {
    				ptr = ptr->right;
    			} else { // Only assigns to parent if larger than val
    				parent = ptr;
    				ptr = ptr->left;
    			}
    		}
    		return parent;
    	}
    	return NULL;
    }
    int kSmallest(treeNode *root, int &k) {
    	if(!root) return -1;
    	int k1 = kSmallest(root->left, k);
    	if(k == 0) return k1; // found required answer above
    	if(--k == 0) return root->data; // main return condition which returns root which is kth
    	// if not found above, must go to right subtree
    	return kSmallest(root->right, k);
    }

    int findKSmallest(int k) {
    	return kSmallest(root, k);
    }
};

// Iterative approach to flatten a tree
treeNode * flatten(treeNode * root) {
    if(root == NULL) return NULL:
    treeNode * p = root; // our pointer that does the swapping of links
    while(p) {
        if(p->left) {
            p = p->left;
            treeNode * r = p->right;

            // move to the last element in left subtree
            while(r->right) r = r->right;
            r->right = p->right;
            p->right = p->left;
            p->left = NULL;
        }
        p = p->right;
    }
    return root;
}

int main()
{
    bst b;
    b.insertNode(52);
    b.insertNode(25);
    b.insertNode(50);
    b.insertNode(15);
    b.insertNode(40);
    b.insertNode(45);
    b.insertNode(20);
    cout << b.findKSmallest(1);
}
