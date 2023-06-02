// Preorder Tree Traversal – Iterative and Recursive
// Given a binary tree, write an iterative and recursive solution to traverse the tree using preorder traversal in C++

// Recursive Solution: 

vector<int> v;
void preorder(Node* root){
    if(root == NULL) return;
    v.push_back(root->val);
    preorder(root->left);
    preorder(root->right);
}

// Time Complexity : O(n)
// Space Complexity : O(h)

// Iterative solution : 

vector<int> preorder(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* curr = s.top();
        s.pop();
        ans.push_back(curr -> val);
        if(root->right != NULL) s.push(root->right);
        if(root->left != NULL) s.push(root->left);
    }
    return ans;
}

// Time Complexity : O(n)
// Space Complexity : O(h)
