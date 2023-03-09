// Shift all matrix elements by 1 in spiral order
// Given an M × N integer matrix, shift all its elements by 1 in spiral order.

void shiftSpiral(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    int top = 0, bottom = n-1, left = 0, right = m-1;
    int prev = mat[0][0];
    while(true){
        if(left > right) break;
        for(int i = left; i<= right; i++){
            swap(mat[top][i], prev);
        }
        top++;
        if(top > bottom) break;
        for(int i = top; i<= bottom; i++){
            swap(mat[i][right], prev);
        }
        right--;
        if(left > right) break;
        for(int i = right; i>= left; i--){
            swap(mat[bottom][i], prev);
        }
        bottom--;
        if(top > bottom) break;
        for(int i=bottom; i>= top; i--){
            swap(mat[left][i], prev);
        }
        left++;
    }
    mat[0][0] = prev;
}


// Time Complexity : O(n)
// Space Complexity : O(n)

