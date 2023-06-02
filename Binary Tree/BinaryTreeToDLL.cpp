// In-place convert a binary tree to a doubly-linked list
// Given a binary tree, in-place convert it into a doubly linked list.
// The conversion should be done such that the left and right pointers of binary tree nodes should act as previous and next pointers in a doubly-linked list, and the doubly linked list nodes should follow the same order of nodes as inorder traversal on the tree.


Node* prev = NULL;
Node* head = NULL;
void BTtoDLL(Node* root){
    if(root == NULL) return;
    BTtoDLL(root->left);
    if(prev == NULL) head = root;
    else{
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTtoDLL(root->right);
}

// Time Complexity : O(n)
// Space Complexity : O(h)

