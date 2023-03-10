// Report all occurrences of an element in a row-wise and column-wise sorted matrix in linear time
// Given an M × N matrix, which is row-wise and column-wise sorted (with all strictly increasing elements in any row or column), report all occurrences of a given element in it in linear time.

vector<pair<int, int>> occurrences(vector<vector<int>>& mat, int target){
    int n = mat.size(), m = mat[0].size();
    int i = 0, j = m-1;
    vector<pair<int, int>> res;
    while(i < n && j >= 0){
        if(mat[i][j] < target) i++;
        else if(mat[i][j] > target) j--;
        else{
            res.push_back(make_pair(i, j));
            i++; j--;
        }
    }
    return res;
}

// Time Complexity : O(m+n);
// Space Complexity : O(1)
