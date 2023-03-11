// Find maximum sum `K × K` submatrix in a given `M × N` matrix
// Given an M × N integer matrix, calculate the maximum sum submatrix of size k × k in it in O(M × N) time. Here, 0 < k < M <= N.


vector<vector<int>> getSum(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> sum(n, vector<int>(m, 0));
    for(int i=1; i<n; i++){
        sum[i][0] = mat[i][0] + sum[i-1][0];
    }
    for(int j=1; j<m; j++){
        sum[0][j] = mat[0][j] + sum[0][j-1];
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            sum[i][j] = mat[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    return sum;
}


int maxSum(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    int max_sum = INT_MIN;
    vector<vector<int>> sum = getSum(mat);
    for(int i = k-1; i < n; i++){
        for(int j = k-1; j<m; j++){
            int total = sum[i][j];
            if(i-k >= 0) total -= sum[i-k][j];
            if(j-k >= 0) total -= sum[i][j-k];
            if(i-k >= 0 && j-k >= 0) total += sum[i-k][j-k];
            if(total > max_sum) max_sum = total;
        }
    }
    return max_sum;
}

// Time Complexity : O(N*M)
// Space Complexity : O(N*M)

