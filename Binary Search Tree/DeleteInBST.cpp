// Deletion from BST (Binary Search Tree)
// Given a BST, write an efficient function to delete a given key in it.

Node *getSucc(Node *curr){
    curr = cur->right;
    while(curr != NULL && cuur->left != NULL){
        curr = curr-left;
    }
    return curr;
}

Node* delNode(Node* root, int x){
    if(root == NULL) return root;
    if(x > root->val) delNode(root->right, x);
    else if(x < root->val) delNode(root->left, x);
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node *succ = getSucc(root);
            root->val = succ->val;
            root->right = delNode(root->right, succ->key);
        }
    }
    return root;
}

// Time Complexity : O(h)
// Space Complexity : O(h)

