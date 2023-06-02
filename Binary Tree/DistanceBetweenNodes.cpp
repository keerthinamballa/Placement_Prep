// Find distance between given pairs of nodes in a binary tree
// Given a binary tree, determine the distance between given pairs of nodes in it. The distance between two nodes is defined as the total number of edges in the shortest path from one node to other.

// *** The distance from v to w can be computed as the distance from the root to v, plus the distance from the root to w, minus twice the distance from the root to their lowest common ancestor.***

bool isPresent(Node* root, Node* node){
    if(root == NULL) return false;
    if(root == node) return true;
    return isPresent(root->left, node) || isPresent(root->right, node);
}

int findLevel(Node* root, Node* node, int level){
    if(root == NULL) return INT_MIN;
    if(root == node) return level;
    int left = findLevel(root->left, node, level+1);
    if(left != INT_MIN){
        return left;
    }
    return findLevel(root->right, node, level+1);
}

Node* findLCA(Node* root, Node* x, Node* y){
    if(root == NULL || root == x || root == y) return root;
    Node* left = findLCA(root->left, x, y);
    Node* right = findLCA(root->right, x, y);
    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return root;
}

int findDistance(Node* root, Node* x, Node* y){
    Node* lca = NULL;
    if(isPresent(root, y) && isPresent(root, x)){
        lca = findLCA(root, x, y);
    }
    else return INT_MIN;
    return findLevel(lca, x, 0) + findLevel(lca, y, 0);
}


// Time Complexity : O(n)
// Space Complexity : O(h)

