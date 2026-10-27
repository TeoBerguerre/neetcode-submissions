class Solution {
    public:
    void go(int open, int close, int n, string& cur, vector<string>& res) {
    if ((int)cur.size() == 2 * n) { res.push_back(cur); return; }
    if (open < n) { cur.push_back('('); go(open + 1, close, n, cur, res); cur.pop_back(); }
    if (close < open) { cur.push_back(')'); go(open, close + 1, n, cur, res); cur.pop_back(); }
    }
    vector<string> generateParenthesis(int n) {
    vector<string> res;
    string cur;
    go(0, 0, n, cur, res);
    return res;
    }
    };