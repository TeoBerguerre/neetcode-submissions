class Solution {
    public:
    int minPathSum(vector<vector<int>>& grid) {
    int R = grid.size(), C = grid[0].size();
    for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++) {
    if (r == 0 && c == 0) continue;
    int up = r > 0 ? grid[r - 1][c] : INT_MAX, left = c > 0 ? grid[r][c - 1] : INT_MAX;
    grid[r][c] += min(up, left);
    }
    return grid[R - 1][C - 1];
    }
    };