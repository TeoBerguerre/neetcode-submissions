class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R = matrix.size(), C = matrix[0].size();
        int lo = 0, hi = R * C - 1;
        while (lo <= hi) {
            int m = (lo + hi) / 2;
            int v = matrix[m / C][m % C];
            if (v == target) return true;
            if (v < target) lo = m + 1; else hi = m - 1;
        }
        return false;
    }
};