// Perform vertical traversal of a binary tree
// Given a binary tree, perform vertical traversal on it. In a vertical traversal, nodes of a binary tree are processed in vertical order from left to right. Assume that the left and right child makes a 45–degree angle with the parent.

void find(Node* root, int dist, map<int, vector<int>> &m){
    if(root == NULL) return;
    m[dist].push_back(root->val);
    find(root->left, dist-1, m);
    find(root->right, dist+1, m);
}

void verticalTraversal(Node* root){
    map<int, vector<int>> m;
    find(root, 0, m);
    for(auto x : m){
        cout<<m.second<<endl;
    }
}

// Time Complexity : O(nlogn)
// Space Complexity : O(n)

