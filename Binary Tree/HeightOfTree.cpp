// Calculate the height of a binary tree – Iterative and Recursive
// Write an efficient algorithm to compute the binary tree’s height. The height or depth of a binary tree is the total number of edges or nodes on the longest path from the root node to the leaf node.

// Recursive: 

int height(Node* root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Time Complexity : O(n)
// Space Complexity : O(h)

// Iterative:

int height(Node* root){
    if(root == NULL) return 0;
    int level = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int count = q.size();
        level+=1;
        for(int i=0; i<count; i++){
            Node* curr = q.front();
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr -> right) q.push(curr->right);
        }
    }
    return level;
}

// Time Complexity : O(n)
// Space Complexity : O(n)




