// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.


bool dfs(vector<vector<char>>& mat, string word, int i, int j, int count){
    if(i < 0 || j < 0 || i >= n || j >= m) return false;
    if(mat[i][j] != word[count] || mat[i][j] == 'V') return false;
    if(count == word.length() - 1) return true;
    char c = mat[i][j];
    mat[i][j] = 'V';
    bool res = dfs(mat, word, i-1, j, count+1) || dfs(mat, word, i+1, j, count+1) || dfs(mat, word, i, j-1, count+1) || dfs(mat, word, i, j+1, count+1);
    mat[i][j] = c;
    return res;
}


bool searchWord(vector<vector<char>>& mat, string word){
    int n = mat.size(), m = mat[0].size();
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dfs(mat, word, i, j, 0)) return true;
        }
    }
    return false;
}

// Time Complexity : O(n*m)
// Space Complexity : O(1)


