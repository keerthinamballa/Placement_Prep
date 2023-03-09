// 54. Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.


vector<int> spiralOrder(vector<vector<int>>& matrix){
    int n = matrix.size(); //rows
    int m = matrix[0].size(); //columns
    int top = 0, bottom = n-1, left = 0, right = m-1;
    while(true){
        if(left > right) break;
        for(int i=left; i<=right; i++){
            res.push_back(matrix[top][i]);
        }
        top++;
        if(top > bottom) break;
        for(int i=top; i<= bottom; i++){
            res.push_back(matrix[i][right]);
        }
        right--;
        if(left > right) break;
        for(int i=right; i>=left; i--){
            res.push_back(matrix[bottom][i]);
        }
        bottom++;
        if(top > bottom) break;
        for(int i=bottom; i>=top; i--){
            res.push_back(matrix[i][left]);
        }
        left++
    }
    return res;
}

// Time Complexity : O(n*m)
// Space Complexity : O(1)
