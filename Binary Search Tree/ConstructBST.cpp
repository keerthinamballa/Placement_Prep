// Construct a balanced BST from the given keys
// Given an unsorted integer array that represents binary search tree (BST) keys, construct a height-balanced BST from it. For each node of a height-balanced tree, the difference between its left and right subtree height is at most 1.

Node* construct(vector<int> &arr, int low, int high){
    if(low > high) return NULL;
    int mid = low + (high-low)/2;
    Node *root = new Node(arr[mid]);
    root->left = construct(arr, low, mid-1);
    root->right = construct(arr, mid+1, high);
    return root;
}

Node* constructBST(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    Node * root = construct(arr, 0, n-1);
    return root;
}

// Time Complexity : O(n)
// Space Complexity : O(h)

