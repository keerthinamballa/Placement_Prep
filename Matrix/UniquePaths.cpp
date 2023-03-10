// 62. Unique Paths
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.


//Using DP

int countPaths(int i, int j, int m, int n, vector<vector<int>>& dp){
    if(i == m-1 && j == n-1) return 1;
    if(i >= m || j >= n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    else dp[i][j] = countPaths(i+1, j, m, n, dp) + countPaths(i, j+1, m, n, dp);
}

int uniquePaths(int m, int n){
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    return countPaths(0, 0, m, n, dp);
}

// Using Maths

int uniquePaths(int m, int n){
    int N = m + n -2, r = m-1;
    double ans = 1;
    for(int i=1; i<= r; i++){
        ans = ans * (N-r+i)/i;
    }
    return (int)ans;
}


