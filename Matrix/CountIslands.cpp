// 200. Number of Islands
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.


void dfs(vector<vector<char>>& grid, int x, int y, int n, int m){
    if(x < 0 || y<0 || x>=n|| y>=m) return;
    if(grid[x][y] != '1') return;
    grid[x][y] = 'V';
    dfs(grid, x-1, y, n, m);
    dfs(grid, x+1, y, n, m);
    dfs(grid, x, y-1, n, m);
    dfs(grid, x, y+1, n, m);
}


int number(vector<vector<char>>& grid){
    int n = grid.size(), m = grid[0].size(), count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '1'){
                dfs(grid, i, j, n, m);
                count++;
            }
        }
    }
    return count;
}

// Time Complexity : O(n*m)
// Space Complexity : O(1)

