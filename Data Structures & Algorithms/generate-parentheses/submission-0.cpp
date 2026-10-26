class Solution {
    vector<string> res;
    void go(string& cur, int open, int close, int n) {
        if ((int)cur.size() == 2 * n) { res.push_back(cur); return; }
        if (open < n) { cur.push_back('('); go(cur, open + 1, close, n); cur.pop_back(); }
        if (close < open) { cur.push_back(')'); go(cur, open, close + 1, n); cur.pop_back(); }
    }
public:
    vector<string> generateParenthesis(int n) { res.clear(); string cur; go(cur, 0, 0, n); return res; }
};