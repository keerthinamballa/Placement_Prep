// Convert a binary tree to BST by maintaining its original structure
// Convert a given binary tree into a BST (Binary Search Tree) by keeping its original structure intact.

void convert(Node* root, auto &it){
    if(root == NULL) return;
    convert(root->left, it);
    root->val = *it;
    it++;
    convert(root->right, it);
}

void extractKeys(Node* root, set<int> &s){
    if(root == NULL) return;
    extractKeys(root->left, s);
    s.insert(root->val);
    extractKeys(root->right, s);
}

void convertToBST(Node* root){
    set<int> s;
    extractKeys(root, s);
    auto it = s.begin();
    convert(root, it);
}

// Time Complexity : O(nlogn)
// Space Complexity : O(n)

