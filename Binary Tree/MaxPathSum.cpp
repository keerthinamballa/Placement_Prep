// 124. Binary Tree Maximum Path Sum
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.

int find(Node* root, int &ans){
    if(root == NULL) return 0;
    int left = find(root->left, ans);
    int right = find(root->right, ans);
    ans = max({ans, l+root->val, r+root->val, l+r+root->val});
    return max({max(l, r)+root->val, root->val});
}

int maxSum(Node* root){
    int ans = INT_MIN;
    find(root, ans);
    return ans;
}

// Time Complexity : O(n)
// Space Complexity : O(h)

