// 1091. Shortest Path in Binary Matrix
// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

int di[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dj[8] = {1, 1, 1, 0, -1, -1, -1, 0};

void find(int i, int j, int dist, int &res, vector<vector<int>> &grid, int n){
    if(i == n-1 && j == n-1){
        res = min(res, dist);
        return;
    }

    grid[i][j] = 2;

    for(int k = 0; k<8; k++){
        int ni = i + di[k];
        int nj = j + dj[k];
        if(ni >=0 && ni < n && nj >=0 && nj < n && grid[i][j] == 0){
            find(ni, nj, dist+1, res, grid, n);
        }
    }

    grid[i][j] = 0;
}

int shortestPath(vector<vector<int>> &grid){
    int n = grid.size();
    if(n == 0 || grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
    int res = INT_MAX;
    find(0, 0, 1, res, grid, n);
    if(res != INT_MAX) return res;
    return -1;
}

Time Complexity : exponential

