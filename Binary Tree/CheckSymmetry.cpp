// Check if a binary tree is symmetric or not
// Given a binary tree, write an efficient algorithm to check if it has a symmetric structure or not, i.e., left and right subtree mirror each other.

bool isSymmetric(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL) return true;
    if(r1 || r2) return false;
    return isSymmetric(r1->left, r2->right) && isSymmetric(r1->right, r2->left);
}

bool checkSymmetry(Node* root){
    if(root == NULL) return true;
    return isSymmetric(root->left, root->right);
}


// Time Complexity : O(n)
// Space Complexity : O(h)


