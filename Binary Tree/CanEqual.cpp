// Determine if a binary tree can be converted to another by doing any number of swaps of children
// Given a binary tree, write an efficient algorithm to determine if it can be converted into another binary tree by doing any number of swaps of its right and left branches.

bool canEqual(Node* r1, Node* r2){
    if(r1 == r2) return true;
    return (r1->val == r2->val) &&((canEqual(r1->left, r2->left) && canEqual(r1->right, r2->right)) || (canEqual(r1->left, r2->right) && canEqual(r1->right, r2->left)));
}

// Time Complexity : O(n^2)
// Space Complexity : O(h)
