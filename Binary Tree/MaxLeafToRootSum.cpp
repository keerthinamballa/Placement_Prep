// Maximum sum leaf to root path
// Given a Binary Tree, find the maximum sum path from a leaf to root.

int maxSum(Node* root){
    if(root == NULL) return INT_MIN;
    if(root->left == NULL && root->right == NULL) return root->val;
    int left = maxSum(root->left);
    int right = maxSum(root->right);
    return max(left, right) + root->val;
}

// Time Complexity : O(n)
// Space Complexity : O(h)


