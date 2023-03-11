// Fill binary matrix with alternating rectangles of 0 and 1
// Given an M × N binary matrix, fill it with alternating rectangles of 1’s and 0’s.


vector<vector<int>> fillMatrix(int n, int m){
    vector<vector<int>> mat(n, vector<int>(m));
    int top = 0, bottom = n-1, left = 0, right = m-1;
    bool flag = 1;
    while(true){
        if(left > right) break;
        for(int i=left; i<=right; i++){
            mat[top][i] = flag;
        }
        top++;
        if(top > bottom) break;
        for(int i=top; i<= bottom; i++){
            mat[i][right] = flag;
        }
        right--;
        if(left > right) break;
        for(int i=right; i>=left; i--){
            mat[bottom][i] = flag;
        }
        bottom--;
        if(top > bottom) break;
        for(int i=bottom; i>= top; i--){
            mat[i][left] = flag;
        }
        left++;
        flag = !flag;
    }
    return mat;
}

// Time Complexity : O(m*n)
// Space Complexity : O(1)


