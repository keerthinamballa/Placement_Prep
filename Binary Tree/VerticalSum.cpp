// Find the vertical sum of a binary tree
// Given a binary tree, the print vertical sum of it. Assume the left and right child of a node makes a 45–degree angle with the parent.

void getSum(Node* root, int dist, map<int, int> &m){
    if(root == NULL) return;
    m[dist] += root->val;
    getSum(root->left, dist-1, m);
    getSum(root->right, dist+1, m);
}

void printVerticalSum(Node* root){
    map<int, int> m;
    getSum(root, 0, m);
    for(auto x : m){
        cout<<x.first<<" "<<x.second<<endl;
    }
}

// Time Complexity : O(nlogn)
// Space Complexity : O(n)

