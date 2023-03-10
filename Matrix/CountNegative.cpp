// 1351. Count Negative Numbers in a Sorted Matrix
// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

int countNegative(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    int i = 0, j = m-1, count = 0;
    while(i < n && j >= 0){
        if(mat[i][j] < 0){
            count += (n-i);
            j--;
        }
        else i++;
    }
    return count;
}

// Time Complexity : O(n+m)
// Space Complexity : O(1)


 