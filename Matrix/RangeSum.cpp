// 304. Range Sum Query 2D - Immutable
// Given a 2D matrix matrix, handle multiple queries of the following type:
// ->Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// Implement the NumMatrix class:
// -> NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
// -> int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// You must design an algorithm where sumRegion works on O(1) time complexity.

class NumMatrix{
public:
    vector<vector<int>> sum;
    NumMatrix (vector<vector<int>>& matrix){
        int n = matrix.size(), m = matrix[0].size();
        sum = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        sum[0][0] = matrix[0][0];
        for(int i=1; i<n; i++){
            sum[i][0] = matrix[i][0] + sum[i-1][0];
        }
        for(int j=1; j<m; j++){
            sum[0][j] = matrix[0][j] + sum[0][j-1];
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                sum[i][j] = matrix[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2){
        int sum = sum[row2][col2];
        if(row1-1 >= 0) sum -= sum[row1-1][col2];
        if(col1-1 >= 0) sum -= sum[row2][col1-1];
        if(row1-1 >= 0 && col1-1 >= 0) sum += sum[row1-1][col1-1];
        return sum;
    }
};

// Time Complexity : O(n + m^2);


//Same Algorithm in different way

vector<vector<int>> getSum(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> res(n, vector<int>(m, 0));
    res[0][0] = mat[0][0];
    for(int i=1; i<n; i++){
        res[i][0] = mat[i][0] + res[i-1][0];
    }
    for(int j=1; j<m; j++){
        res[0][j] = mat[0][j] + res[0][j-1];
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            res[i][j] = mat[i][j] + res[i-1][j] + res[i][j-1] - res[i-1][j-1];
        }
    }
    return res;
}

int findSum(vector<vector<int>>& mat, int r1, int c1, int r2, int c2){
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> sum = getSum(mat);
    int ans = sum[r2][c2];
    if(r1-1 >= 0) ans -= sum[r1-1][c2];
    if(c1-1 >= 0) ans -= sum[r2][c1-1];
    if(r1-1 >= 0 && c1-1 >= 0) ans += sum[r1-1][c1-1];
    return ans;
}

// Time Complexity : O(n*m + n + m)
// Space Complexity : O(n*m)


