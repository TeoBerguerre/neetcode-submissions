class Solution {
    int cnt;
    vector<bool> cols, d1, d2;
    void go(int r, int n) {
        if (r == n) { cnt++; return; }
        for (int c = 0; c < n; c++) {
            if (cols[c] || d1[r + c] || d2[r - c + n - 1]) continue;
            cols[c] = d1[r + c] = d2[r - c + n - 1] = true;
            go(r + 1, n);
            cols[c] = d1[r + c] = d2[r - c + n - 1] = false;
        }
    }
public:
    int totalNQueens(int n) {
        cnt = 0; cols.assign(n, false); d1.assign(2 * n, false); d2.assign(2 * n, false);
        go(0, n);
        return cnt;
    }
};