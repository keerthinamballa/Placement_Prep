// Check if a binary tree is a complete binary tree or not
// Given a binary tree, check if it is a complete binary tree or not.

// A complete binary tree is a binary tree in which every level, except possibly the last, is filled, and all nodes are as far left as possible.

bool isComplete(Node* root){
    if(root == NULL) return true;
    queue<Node*> q;
    q.push(root);
    bool flag = flase;
    while(!q.empty()){
        int n = q.size();
        while(n--){
            Node* curr = q.front();
            if(flag && (curr->left || curr->right)) return false;
            if(curr->left == NULL && curr->right) return false;
            if(curr->left) q.push(curr->left);
            else flag = true;
            if(curr->right) q.push(curr->right);
            else flag = true;
        }
    }
    return true;
}


// Time Complexity : O(n)
// Space Complexity : O(n)


