// Truncate a binary tree to remove nodes that lie on a path having a sum less than `k`
// Given a binary tree and a number k, remove nodes from the tree which lie on a complete path having a sum less than k. A complete path in a binary tree is defined as a path from the root to a leaf. The sum of all nodes on that path is defined as the sum of that path.

void trunc(Node* curr, int k, int &target){
    if(curr == NULL) return;
    target += curr->val;
    trunc(curr->left, k, target);
    trunc(curr->right, k, target);
    if(target<k && isLeaf(curr)){
        delete(curr);
        curr = NULL;
    }
}

Node* getFinal(Node* root, int k){
    int target = 0;
    trunc(root, k, target);
    return root;
}

// Time Complexity : O(n)
// Space Complexity : O(h)



