// Find the probability that a person is alive after taking `n` steps on an island
// An island is in the form of a square matrix, and a person is standing inside the matrix. The person can move one step in any direction (right, left, top, down) in the matrix. Calculate the probability that the person is alive after walking n steps on the island, provided that the person dies on stepping outside the matrix.


bool isSafe(int x, int y, int n, int m){
    return x >= 0 && y >= 0 && x < n && y < m;
}


double aliveProbability(vector<vector<int>>& mat, int x, int y, int N){
    int n = mat.size(), m = mat[0].size();
    if(!isSafe(x, y, n, m)) return 0.0;
    if(N == 0) return 1.0;
    double prob = 0.0;
    prob += aliveProbability(mat, x+1, y, N-1)*0.25;
    prob += aliveProbability(mat, x-1, y, N-1)*0.25;
    prob += aliveProbability(mat, x, y-1, N-1)*0.25;
    prob += aliveProbability(mat, x, y+1, N-1)*0.25;
    return prob;
}

// Time Complexity : O(n^2)
// Space Complexity : O(1)

