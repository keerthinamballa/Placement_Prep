// Print all paths from the root to leaf nodes of a binary tree
// Given a binary tree, write an efficient algorithm to print all paths from the root node to every leaf node in it.

bool isLeaf(Node* node){
    return node->left == NULL && node->right == NULL;
}

void find(Node* root, vector<int> &path, vector<vector<int>> &ans){
    if(root == NULL) return;
    path.push_back(root->val);
    if(isLeaf(root)){
        ans.push_back(path);
        return;
    }
    find(root->left, path, ans);
    find(root->right, path, ans);
    path.pop_back();
}

vector<vector<int>> rootToLeaf(Node* root){
    vector<vector<int>> ans;
    vector<int> path;
    if(root == NULL) return ans;
    find(root, path, ans);
    return ans;
}

// Time Complexity : O(n)
// Space Complexity : O(h)

