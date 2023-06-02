// Reverse level order traversal of a binary tree
// Given a binary tree, print its nodes level by level in reverse order, i.e., print all nodes present at the last level first, followed by nodes of the second last level, and so on… Print nodes at any level from left to right.

void reverseLevelOrder(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    stack<int> s;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        s.push(curr->val);
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

// Using hashmaps:

void preorder(Node* root, unordered_map<int, vector<int>> &m, int level){
    if(root == NULL) return;
    m[level].push_back(root->val);
    preorder(root->left, m, level+1);
    preorder(root->right, m, level+1);
}

void reverseLevelOrder(Node* root){
    unordered_map<int, vector<int>> m;
    preorde(root, m, 1);
    for(int i = m.size(), i>=0; i--){
        for(int k : m[i]){
            cout<<k<<" ";
        }
    }
    cout<<endl;
}

// Time Compleity : O(n)
// Space Complexity : O(n)


