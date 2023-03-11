// Construct a binary tree from an ancestor matrix
// Given an N × N ancestor matrix, whose cell (i, j) has the value true if i is the ancestor of j in a binary tree, construct a binary tree from it where binary tree nodes are labeled from 0 to N-1.


Node* construct(vector<vector<int>>& mat){
    int n = mat.size();
    multimap<int, int> m;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            sum += mat[i][j];
        }
        m.insert({sum, i});
    }

    vector <Node*> node(n);
    vector<bool> parent(n, false);
    int row;
    for(int x : m){
        row = x.second;
        node[row] = new Node(row);
        if(x.first == 0) continue;
        for(int i=0; i<n; i++){
            if(parent[i] == false && mat[row][i]){
                if(node[row] -> left == NULL){
                    node[row] -> left = node[i];
                }
                else{
                    node[row]->right = node[i];
                }
                parent[i] = true;
            }
        }
    }
    return node[row];
}

// Time Complexity : O(n*n)
// Space Complexity : O(n)


