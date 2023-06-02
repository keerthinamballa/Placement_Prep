// Convert a binary tree to a full tree by removing half nodes
// Given a binary tree, convert it into a full tree by removing half nodes (remove nodes having one child). A full binary tree is a tree in which every node other than the leaves has two children.

bool isLeaf(Node* node){
    return node->left == NULL && node->right == NULL;
}

Node* truncate(Node* root){
    if(root == NULL) return root;
    root->left = truncate(root->left);
    root->right = truncate(root->right);
    if((root->left && root->right) || isLeaf(root)) return root;
    Node* child = root->left ? root->left : root->right;
    delete root;
    return child;
}

// Time Complexity : O(n)
// Space Complexity : O(h)


