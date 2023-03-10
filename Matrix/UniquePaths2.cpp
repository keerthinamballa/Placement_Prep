// 63. Unique Paths II
// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

//Memoization Method:

int solve(int i, int j, int n, int m, vector<vector<int>>& mat, vector<vector<int>>& dp){
    if(i > = n || j >= m || mat[i][j] == 1) return 0;
    if(i == n-1 && j == m-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = solve(i+1, j, n, m, mat, dp) + solve(i, j+1, n, m, mat, dp);
}

int uniquePaths(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return solve(0, 0, n, m, mat, dp);
}

//Tabulation Method:

int uniquePaths(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 1) return 0;
            else if( i == 0 && j == 0) dp[i][j] = 1;
            else{
                int up = 0, left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}


// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

