// Check if the given keys represent the same BSTs or not without building BST
// Given two integer arrays, X and Y, representing a set of BST keys, check if they represent the same BSTs or not without building the tree. Assume that the keys are inserted into the BST in the same order as they appear in the array.

bool isSame(vector<int> &v1, vector<int> &v2){
    if(v1 == v2) return true;
    if(v1.size() != v2.size()) return false;
    if(v1[0] != v2[0]) return false;
    vector<int> l1, r1, l2, r2;
    for(int i=1; i<v1.size(); i++){
        int t1 = v1[0];
        if(v1[i] < t1) l1.push_back(v1[i]);
        else r1.push_back(v1[i]);

        int t2 = v2[0];
        if(v2[i] < t2) l2.push_back(v2[i]);
        else r2.push_back(v2[i]);
    }

    int left = isSame(l1, l2);
    int right = isSame(r1, r2);
    return left&&right;
}

// Time Complexity : O(n^2)
// Space Complexity : O(n)

