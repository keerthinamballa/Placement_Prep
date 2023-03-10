// 48. Rotate Image
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.


void rotate(vector<vector<int>>& mat){
    int n = mat.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        reverse(mat[i].begin(), mat[i].end());
    }
}

// Time Complexity : O(n^2)
// Space Complexity : O(1)


