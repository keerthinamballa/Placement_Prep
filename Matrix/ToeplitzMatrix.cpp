// 766. Toeplitz Matrix
// Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
// A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

bool isToeplitz(vector<vector<int>& mat){
    int n = mat.size(), m = mat[0].size();
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(mat[i-1][j-1] != mat[i][j]) return false;
        }
    }
    return true;
}

// Time Complexity : O(n*m)
// Space Complexity : O(1)
