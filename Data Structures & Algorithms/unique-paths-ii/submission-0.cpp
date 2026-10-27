class Solution {
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int R = obstacleGrid.size(), C = obstacleGrid[0].size();
    vector<long long> dp(C, 0);
    dp[0] = 1;
    for (int r = 0; r < R; r++)
    for (int c = 0; c < C; c++) {
    if (obstacleGrid[r][c]) dp[c] = 0;
    else if (c > 0) dp[c] += dp[c - 1];
    }
    return dp[C - 1];
    }
    };