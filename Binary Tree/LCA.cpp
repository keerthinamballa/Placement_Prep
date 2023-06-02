// Find the Lowest Common Ancestor (LCA) of two nodes in a binary tree
// Given a binary tree and two nodes, x and y, find the lowest common ancestor (LCA) of x and y in it. The solution should return null if either x or y is not the actual node in the tree.

// Using path array:

bool findPath(Node* root, vector<Node*> &p, int n){
    if(root == NULL) return false;
    p.push_back(root);
    if(root->val == n) return true;
    if(findPath(root->left, p, n) || findPath(root->right, p, n)) return true;
    p.pop_back();
    return false;
}

Node* LCA(Node* root, int n1, int n2){
    vector<Node*> path1, path2;
    if(findPath(root, path1, n1) == false || findPath(root, pzth2, n2) == false) return NULL;
    for(int i=0; i<path1.size() - 1 && i < path2.size()-1; i++){
        if(path1[i+1] != path2[i+1]) return path1[i];
    }
    return NULL;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

Node* lca(Node* root, Node* p, Node* q){
    if(root == NULL || root == p || root == q){
        return root;
    }
    Node* left = lca(root->left, p, q);
    Node* right = lca(root->right, p, q);
    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return root;
}

// Time Complexity : O(n)
// Space Complexity : O(n)



