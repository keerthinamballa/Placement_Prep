// Delete a binary tree – Iterative and Recursive
// Given a binary tree, write an efficient algorithm to delete the entire binary tree. The algorithm should deallocate every single node present in the tree, not just change the root node’s reference to null.

// Recursive:

void deleteBinaryTree(Node* root){
    if(root == NULL) return;
    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);
    delete root;
    root = NULL;
}

// Time Complexity : O(n)
// Space Complexity : O(h)

void deleteBinaryTree(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
        delete curr;
    }
    delete root;
}

// Time Complexity : O(n)
// Space Complexity : O(n)
