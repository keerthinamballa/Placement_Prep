// Find the diagonal sum of a binary tree
// Given a binary tree, calculate the sum of all nodes for each diagonal having negative slope \. Assume that the left and right child of a node makes a 45–degree angle with the parent.

void find(Node* root, int diagonal, map<int, int> &m){
    if(root == NULL) return;
    m[diagonal] += root->val;
    find(root->left, diagonal+1, m);
    find(root->right, diagonal, m);
}

void diagonalSum(Node* root){
    map<int, int> m;
    find(root, 0, m);
    for(auto it : m){
        cout<<it.second<<" ";
    }
}

// Time Complexity : O(nlogn)
// Space Complexity : O(n)


