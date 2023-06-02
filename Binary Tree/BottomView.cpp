// Print bottom view of a binary tree
// Given a binary tree, print the bottom view of it. Assume the left and right child of a node makes a 45–degree angle with the parent.

void preorder(Node*root, int dist, int level, map<int,pair<int, int>> &m){
    if(root == NULL) return;
    m[level] = {root->val, dist};
    preorder(root->left, dist - 1, level+1, m);
    preorder(root->right, dist+1, level+1, m);
}

void bottomView(Node* root){
    map<int, pair<int, int>> m;
    preorder(root, 0, 0, m);
    for(auto it: m){
        cout<<it.second.first<<" ";
    }
}

// Time Complxity : O(nlogn)
// Space Complexity : O(n)

