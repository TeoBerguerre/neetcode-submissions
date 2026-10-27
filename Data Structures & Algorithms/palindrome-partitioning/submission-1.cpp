class Solution {
    public:
    bool pal(const string& s, int l, int r) { while (l < r) if (s[l++] != s[r--]) return false; return true; }
    void go(const string& s, int start, vector<string>& cur, vector<vector<string>>& res) {
    if (start == (int)s.size()) { res.push_back(cur); return; }
    for (int end = start; end < (int)s.size(); end++) {
    if (!pal(s, start, end)) continue;
    cur.push_back(s.substr(start, end - start + 1));
    go(s, end + 1, cur, res);
    cur.pop_back();
    }
    }
    vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> cur;
    go(s, 0, cur, res);
    return res;
    }
    };