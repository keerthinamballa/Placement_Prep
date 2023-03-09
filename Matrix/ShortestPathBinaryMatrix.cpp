// 1091. Shortest Path in Binary Matrix
// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
// -> All the visited cells of the path are 0.
// -> All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.


int shortestPathBinaryMatrix(vector<vector<int>>& grid){
    int n = grid.size();
    if(grid[0][0] || grid[n-1][n-1]) return -1;
    queue <pair<pair<int, int>, int>> q;
    q.push({{0,0}, 1});
    grid[0][0] = 1;
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        int x = t.first.first, y = t.first.second, path_len = t.second;
        if(x == n-1 && y == n-1) return path_len;
        for(auto d: dir){
            int i = x+d[0], j = y+d[1];
            if(i >=0 && j >= 0 && i<n&& j<n && !grid[i][j]){
                grid[i][j] = 1;
                q.push({{i,j}, path_len+1});
            }
        }
    }
    return -1;
}

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)



