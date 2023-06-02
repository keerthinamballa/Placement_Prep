// Find ancestors of a given node in a binary tree
// Given a binary tree, find all ancestors of a given node in it.


bool find(Node* root, Node* node, vector<int> &v){
    if(root == NULL) return false;
    if(root == node) return true;
    bool left = find(root->left, node, v);
    bool right = false;
    if(!left){
        right = find(root->right, node, v);
    }
    if(left || right) v.push_back(root);
    return left || right;
}

vector<int> getAncestors(Node*root, Node* node){
    vector<int> v;
    if(root == NULL) return v;
    find(root, node, v);
    return v; 
}

// Time Complexity : O(n)
// Space Complexity : O(h)


