// Sink nodes containing zero to the bottom of a binary tree
// Given a binary tree containing many zero nodes, sink nodes having zero value at the bottom of the subtree rooted at that node. In other words, the output binary tree should not contain any node having zero value that is the parent of the node having a non-zero value.

void sink(Node* root){
    if(root == NULL) return;
    if(root->left && root->left->val != 0){
        swap(root->val, root->left->val);
        sink(root->left);
    }
    else if(root->right && root->right->val != 0){
        swap(root->val, root->right->val);
        sink(root->right);
    }
}


void sinkNodes(Node* root){
    if(root == NULL) return;
    sinkNodes(root->left);
    sinkNodes(root->right);
    if(root->val == 0){
        sink(root);
    }
}

// Time Complexity : O(n^2)
// Space Complexity : O(h)
