// Find inorder predecessor for the given key in a BST
// Given a BST, find the inorder predecessor of a given key in it. If the key does not lie in the BST, return the previous greater node (if any) present in the BST.

Node *inorderPredecessor(Node* root, int key){
    Node* pred = NULL;
    while(root != NULL){
        if(root->val < key){
            pred = root;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return pred;
}

// Time Complexity : O(n)
// Space Complexity : O(1)


