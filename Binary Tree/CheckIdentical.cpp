// Check if two binary trees are identical or not – Iterative and Recursive
// Write an efficient algorithm to check if two binary trees are identical or not. Two binary trees are identical if they have identical structure and their contents are also the same.

// Recursive Code:

bool areIdentical(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL) return true;
    if(r1 == NULL||r2 == NULL) return false;
    return (r1->val == r2->val && areIdentical(r1->left, r2->left) && areIdentical(r1->right, r2->right));
}

// Time Complexity : O(n)
// Space Complexity : O(h)

// Iterative Code: 

bool areIdentical(Node* r1, Node* r2){
    if(r1 == NULL && r2 == NULL) return true;
    if(r1 == NULL || r2 == NULL) return false;
    queue<pair<Node*, Node*>> q;
    q.push({r1, r2});
    while(!q.empty()){
        Node* x = q.front().first;
        Node* y = q.front().second;
        if(x->val != y->val) return false;

        if(x->left && y->left){
            q.push({x->left, y->left});
        } 

        else if(x->left || y->left) return false;

        if(x->right && y->right){
            q.push({x->right, y->right});
        }

        else if(x->right || y->right) return false;
    }
    return true;
}

// Time Complexity : O(n)
// Space Complexity : O(n)



