// 701. Insert into a Binary Search Tree
// You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
// Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

// Recursive solution:

Node* insert(Node* root, int x){
    if(root == NULL) return new Node(x);
    if(x > root->val) root->right = insert(root->right, x);
    else if(x < root->val) root->left = insert(root->left, x);
    return root;
}

// Iterative Solution:

Node* insert(Node* root, int x){
    Node* temp = new Node(x);
    Node *parent = NULL, *curr = root;
    while(curr != NULL){
        parent = curr;
        if(x > curr->val) curr = curr->right;
        else if(x < curr->val) curr = curr->left;
        else return root;
    }
    if(parent == NULL) return temp;
    else if(parent->val > x) parent->left = temp;
    else if(parent->val < x) parent->right = temp;
    return root;
}

// Time Complexity : O(h)
// Space Complexity : O(1) in iterative and O(h) for recursive call stack.

