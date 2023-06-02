// Print corner nodes of every level in a binary tree
// Given a binary tree, print corner nodes of every level in it.


void cornerNodes(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* curr = q.front();
            q.pop();
            if(i == 0 || i == n-1){
                cout<<curr->val<<" ";
            }
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }
        cout<<endl;
    }
}

// Time Complexity : O(n)
// Space Complexity : O(n)

