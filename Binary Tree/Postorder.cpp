// Postorder Tree Traversal – Iterative and Recursive
// Given a binary tree, write an iterative and recursive solution to traverse the tree using postorder traversal in C++

vector<int> postorder;
void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    postorder.push_back(root->val);
}

// Iterative:

vector<int> postorder(Node* root){
    vector<int> postorder;
    if(root == NULL) return postorder;
    stack<Node*> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        root = s1.top();
        s1.pop();
        s2.push(root);
        if(root->left != NULL){
            s1.push(root->left);
        }
        if(root->right != NULL){
            s1.push(root->right);
        }
    }
    while(!s2.empty()){
        postorder.push_back(s2.top()->val);
        s2.pop();
    }
    return postorder;
}

// Time Complexity : O(n)
// Space Complexity : O(2n)


// Iterative solution using 1 stack :

vector<int> postorder(Node* root){
    vector<int> postorder;
    if(root == NULL) return postorder;
    stack<Node*> s;
    Node* temp = NULL;
    while(root != NULL || !s.empty()){
        if(root != NULL){
            s.push(root);
            root = root->left;
        }
        else{
            temp = s.top()->right;
            if(temp == NULL){
                temp = s.top();
                s.pop();
                postorder.push_back(temp);
                while(!s.empty() && temp == s.top()->right){
                    temp = s.top();
                    s.pop();
                    postorder.push_back(temp);
                }
            }
            else root = temp;
        }
    }
    return postorder;
}

// Time Complexity : O(2n)
// Space Complexity : O(n)



