// Build a binary tree from a parent array
// Given an integer array representing a binary tree, such that the parent-child relationship is defined by (A[i], i) for every index i in array A, build a binary tree out of it. The root node’s value is i if -1 is present at index i in the array. It may be assumed that the input provided to the program is valid.

Node* construct(vector<int> &parent){
    int n = parent.size();
    unordered_map<int, Node*> m;
    for(int i=0; i<n; i++){
        m[i] = new Node(i);
    }
    Node* root = NULL;
    for(int i=0; i<n; i++){
        if(parent[i] == -1) root = m[i];
        else{
            Node* p = m[parent[i]];
            if(p->left) p->right = m[i];
            else p->left = m[i];
        }
    }
    return root;
}

// Time Complexity : O(n)
// Space Complexity : O(n)


