// In-place convert a binary tree to its sum tree
// Given a binary tree, in-place replace each node’s value to the sum of all elements present in its left and right subtree. You may assume the value of an empty child node to be 0.


void convert(Node* root){
    if(root == NULL) return 0;
    int left = convert(root->left);
    int right = convert(root->right);
    int old = root->val;
    root->val = left+right;
    return root->val + old;
}

// Time Complexity : O(n)
// Space Complexity : O(h)
