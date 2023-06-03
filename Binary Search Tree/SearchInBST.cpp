// Search a given key in BST – Iterative and Recursive Solution
// Given a BST, write an efficient function to search a given key in it. The algorithm should return the parent node of the key and print if the key is the left or right node of the parent node. If the key is not present in the BST, the algorithm should be able to determine that.

// Recursive 

bool search(Node* root, int x){
    if(root == NULL) return false;
    if(root->val == x) return true;
    else if(x > root->val) return search(root->right, x);
    else if(x < root-val) return search(root->left, x);
}

// Iterative solution:

bool search(Node* root, int x){
    if(root == NULL) return false;
    while(root != NULL){
        if(root->key == x) return true;
        else if(x > root->key) root = root->right;
        else if(x < root->key) root = root->left;
    }
    return false;
}


// Time Complexity : O(h)
// Space Complexity : O(h) for recursive call stack and O(1) for iteration.

