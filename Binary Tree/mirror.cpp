// Convert a binary tree to its mirror
// Given a binary tree, write an efficient algorithm to convert the binary tree into its mirror.

void convetToMirror(node* root){
    if(root == NULL) return;
    convetToMirror(root->left);
    convetToMirror(root->right);
    swap(root->left, root->right);
}

// Time Complexity : O(n)
// Space Complexity : O(h)

