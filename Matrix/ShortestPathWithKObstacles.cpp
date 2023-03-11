// 1293. Shortest Path in a Grid with Obstacles Elimination
// You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). You can move up, down, left, or right from and to an empty cell in one step.
// Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.


int shortestPath(vector<vector<int>>& mat, int k){
    int n = mat.size(), m = mat[0].size(), steps = 0;
    vector<vector<int>> remains(n, vector<int>(m, INT_MIN));
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    queue<array<int,3>> q;
    q.push({0,0,k});
    remains[0][0] = k;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto t = q.front();
            q.pop();
            int x = t[0], y = t[1];
            if(x == n-1 && y == m-1) return steps;
            for(auto d : dir){
                int i = x + d[0], j = y + d[1];
                if(i < 0 || j < 0 || i >= n || j >= m) continue;
                int r = t[2] - mat[i][j];
                if(r >= 0 && remains[i][j] < r){
                    q.push({i, j, r});
                    remains[i][j] = r;
                }
            }
        }
        steps++;
    }
    return -1;
}


// Time Complexity : O(n*m)
// Space Complexity : O(n*m)


 