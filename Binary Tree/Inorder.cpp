// Inorder Tree Traversal – Iterative and Recursive
// Given a binary tree, write an iterative and recursive solution to traverse the tree using inorder traversal in C++

vector<int> ans;
void inorder(Node* root, vector<int> &ans){
    if(root == NULL) return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

// Time Complexity : O(n)
// Space Complexity : O(h)

// Iterative:

vector<int> inorder(Node* root){
    vector<int> inorder;
    if(root == NULL) return inorder;
    Node* node = root;
    stack<Node*> s;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }
    return inorder;
}

// Time Complexity : O(n)
// Space Complexity : O(h)



