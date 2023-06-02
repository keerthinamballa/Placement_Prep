// Find the diameter of a binary tree
// Given a binary tree, write an efficient algorithm to compute the diameter of it. A binary tree diameter equals the total number of nodes on the longest path between any two leaves in it.


int find(Node* root, int &res){
    if(root == NULL) return 0;
    int left = find(root->left, res);
    int right = find(root->right, res);
    res = max(res, left+right+1);
    return max(left, right) + 1;
}

int diameter(Node* root){
    int diameter = 0;
    find(root, diameter);
    return diameter;
}


// Time Complexity : O(n)
// Space Complexity : O(h) 

