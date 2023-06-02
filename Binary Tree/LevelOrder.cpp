// Level order traversal of a binary tree
// Given a binary tree, print its nodes level by level, i.e., print all nodes of level 1 first, followed by nodes of level 2 and so on… Print nodes for any level from left to right.


vector<int> levelOrder(Node* root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        ans.push_back(curr->val);
        if(curr -> left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
    return ans;
}

Time Complexity : O(n)
Space Complexity : O(n);


