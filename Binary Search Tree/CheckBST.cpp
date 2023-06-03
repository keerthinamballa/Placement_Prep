// Determine whether a given binary tree is a BST or not
// Given a binary tree, determine whether it is a BST.

bool check(Node *root, int minval, int maxval){
    if(root == NULL) return true;
    if(root->val < minval || root->val > maxval) return false;
    return check(root->left, minval, root->val) && check(root->right, root->val maxval);
}

bool checkBST(Node *root){
    int minval = INT_MIN, maxval = INT_MAX;
    return check(root, minval, maxval);
}

// Time Complexity : O(n)
// Space Complexity : O(h)
