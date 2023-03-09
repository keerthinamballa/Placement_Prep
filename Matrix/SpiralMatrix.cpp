59. Spiral Matrix II
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

vector<vector<int>> generateMatrix(int n){
    vector<vector<int>> mat(n, vector<int>(n));
    if(n == 0)return mat;
    int top = 0, bottom = n-1, left = 0, right = n-1;
    int v = 1;
    while(v <= n*n){
        if(left > right) break;
        for(int i = left; i<=right; i++){
            mat[top][i] = v;
            v++;
        }
        top++;
        if(top > bottom) break;
        for(int i=top; i<=bottom; i++){
            mat[i][right] = v;
            v++;
        }
        right--;
        if(left > right) break;
        for(int i=right; i>= left; i--){
            mat[bottom][i] = v;
            v++;
        }
        bottom--;
        if(top > bottom) break;
        for(int i=bottom; i>=top; i--){
            mat[i][left] = v;
            v++;
        }
        left++;
    }
    return mat;
} 

// Time Complexity : O(n*n)
// Space Complexity : O(1)


