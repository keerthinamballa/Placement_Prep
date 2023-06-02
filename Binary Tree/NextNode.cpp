// Find the next node at the same level as the given node in a binary tree
// Given a binary tree and a node in it, write an efficient algorithm to find its next node at the same level as the node.


// Using Level Order Traversal : 

Node* nextNode(Node* root, Node* node){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        while(n--){
            Node* curr = q.front();
            q.pop();
            if(curr == node){
                if(n == 0) return NULL;
                return q.front();
            }

            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }
    }
    return NULL;
}

// Time Complexity : O(n)
// Space Complexity : O(n)
