class Solution {
    public:
    int R, C;
    void mark(vector<vector<char>>& b, int r, int c) {
    if (r < 0 || c < 0 || r >= R || c >= C || b[r][c] != 'O') return;
    b[r][c] = 'T';
    mark(b, r + 1, c); mark(b, r - 1, c); mark(b, r, c + 1); mark(b, r, c - 1);
    }
    void solve(vector<vector<char>>& board) {
    R = board.size(); C = board[0].size();
    for (int r = 0; r < R; r++) { mark(board, r, 0); mark(board, r, C - 1); }
    for (int c = 0; c < C; c++) { mark(board, 0, c); mark(board, R - 1, c); }
    for (auto& row : board) for (char& ch : row) ch = (ch == 'T') ? 'O' : 'X';
    }
    };