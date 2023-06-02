// Print left view of a binary tree
// Given a binary tree, write an efficient algorithm to print its left view.

int maxlevel = 0;
void leftView(Node* root, int level){
    if(root == NULL) return;
    if(maxlevel < level){
        cout<<root->val;
        maxlevel = level;
    }
    leftView(root->left, level+1);
    leftView(root->right, level+1);
}


// Using BFS:

void leftView(Node* root){
    if(root == NULL) return;
    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* curr = q.front();
            q.pop();
            if(i == 0) cout << curr->val<< " ";
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
}

// Time Complexity : O(n)
// Space complxity : O(n)

