// C++ Matrix Rotation by 180 degree
// Given a square matrix of size N X N, turn it by 180 degrees in anticlockwise direction without using extra memory.

void rotateBy180(vector<vector<int>>& mat){
    int n = mat.size();
    for(int i=0; i<2; i++){
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }
}


// Time Complexity : O(n^2)
// Space Complexity : O(1)


