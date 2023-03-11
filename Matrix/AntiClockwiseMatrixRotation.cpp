// Rotate a 2D array without using extra space
// Given a N x N 2D matrix Arr representing an image. Rotate the image by 90 degrees (anti-clockwise). You need to do this in place. Note that if you end up using an additional array, you will only receive partial score.


void rotateAnticlockwise(vector<vector<int>>& mat){
    int n = mat.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        int top= 0, bottom = n-1;
        while(top < bottom){
            swap(mat[top][i], mat[bottom][i]);
            top++; bottom--;
        }
    }
}

// Time Complexity : O(n*n)
// Space Complexity : O(1)
