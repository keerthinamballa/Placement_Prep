// 498. Diagonal Traverse
// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.


vector<int> diagonalTraversal(vcetor<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    vector<int> res(n*m);
    if(n == 0) return {};
    int i=0, j=0, k=0;
    bool up = true;
    while(i < n && j < m){
        if(up){
            while(i > 0 && j < m-1){
                res[k++] = mat[i][j];
                i--;
                j++;
            }
            res[k++] = mat[i][j];
            if(j == m-1) i++;
            else j++;
        }
        else{
            while(i < n-1 && j > 0){
                res[k++] = mat[i][j];
                i++;
                j--;
            }
            res[k++] = mat[i][j];
            if(i == n-1) j++;
            else i++;
        }
        up = !up;
    }
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(1)



