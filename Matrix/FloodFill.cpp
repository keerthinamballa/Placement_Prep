// 733. Flood Fill
// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
// Return the modified image after performing the flood fill.


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
    int n = image.size(), m = image[0].size();
    if(n == 0) return image;
    int target = image[sr][sc];
    if(color == target) return image;
    image[sr][sc] = color;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for(auto d : dir){
        int x = sr + d[0], y = sc + d[1];
        if(x >= 0 && x < n && y >= 0 && y < m && image[x][y] == target){
            floodFill(image, x, y, color);
        }
    }
    return image;
}

// Time Complexity : O(n*m)
// Space Complexity : O(1)

