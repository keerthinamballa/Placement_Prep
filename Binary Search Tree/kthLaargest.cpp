// Find k’th largest node in a BST
// Given a BST and a positive number k, find the k'th largest node in the BST.

Node* kthLargest(Node* root, int k){
    if(root == NULL) return root;
    Node *root = kthLargest(root->right, k);
    if(right != NULL) return right;
    k--;
    if(k == 0) return root;
    return kthLargest(root->left, k);
}

// Time Complexity : O(n)
// Space Complexity : O(h)


