class Solution {
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int R = matrix.size(), C = matrix[0].size();
    int l = 0, r = R * C - 1;
    while (l <= r) {
    int m = (l + r) / 2;
    int v = matrix[m / C][m % C];
    if (v == target) return true;
    if (v < target) l = m + 1; else r = m - 1;
    }
    return false;
    }
    };