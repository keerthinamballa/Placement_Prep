// Determine whether a given binary tree is a BST or not
// Given a binary tree, determine whether it is a BST.

bool find(Node* root, int minval, int maxval){
    if(root == NULL) return true;
    if(root->val < INT_MIN && root->val > INT_MAX) return false;
    return find(root->left, minval, root->val) && find(root->right, root->val, maxval);
}

bool isBST(Node* root){
    return find(root, INT_MIN, INT_MAX);
}

// Time Complexity : O(n)
// Space Complexity : O(h)

