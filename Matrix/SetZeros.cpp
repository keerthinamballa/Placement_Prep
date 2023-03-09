// 73. Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.


void setMatrixZeros(vector<vector<int>>& matrix){
    int n = matrix.size(), m = matrix[0].size();
    bool row0 = false, col0 = false;
    for(int i=0; i<n; i++){
        if(matrix[i][0] == 0)
            col0 = true;
    }
    for(int i=0; i<m; i++){
        if(matrix[0][i]) 
            row0 = false;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if(row0 == true){
        for(int i=0; i<m; i++){
            matrix[0][i] = 0;
        }
    }
    if(col0 == true){
        for(int i=0; i<n; i++){
            matrix[i][0] = 0;
        }
    }
}

// Time Complexity : O(n*m)
// Space Complexity : O(1)

