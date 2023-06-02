// Invert Binary Tree – Iterative and Recursive Solution
// Given a binary tree, write an efficient algorithm to invert it.


void invertBinaryTree(Node* root){
    if(root == NULL) return;
    swap(root->left, root->right);
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
}

// Time Complexity : O(n)
// Space Complexity : O(h)

