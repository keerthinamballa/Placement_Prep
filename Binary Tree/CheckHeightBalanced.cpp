// Check if a binary tree is height-balanced or not
// Given a binary tree, write an efficient algorithm to check if it is height-balanced or not. In a height-balanced tree, the absolute difference between the height of the left and right subtree for every node is 0 or 1.

bool find(Node* root, bool &isBalanced){
    if(root == NULL || isBalnced == false) return 0;
    int left = find(root->left, isBalanced);
    int right = find(root->right, isBalanced);
    if(abs(left - right) > 1){
        isBalanced = false;
    }
    return max(left, right) + 1;
}

bool isHeightBalanced(Node* root){
    bool isBalanced = true;
    find(root, isBalanced);
    return isBalanced;
}

// Time Complexity : O(n)
// Space Complexity : O(h)
