class Solution {
    vector<vector<string>> res;
    vector<string> cur;
    bool pal(const string& s, int l, int r) { while (l < r) if (s[l++] != s[r--]) return false; return true; }
    void go(const string& s, int i) {
        if (i == (int)s.size()) { res.push_back(cur); return; }
        for (int j = i; j < (int)s.size(); j++)
            if (pal(s, i, j)) { cur.push_back(s.substr(i, j - i + 1)); go(s, j + 1); cur.pop_back(); }
    }
public:
    vector<vector<string>> partition(string s) { res.clear(); cur.clear(); go(s, 0); return res; }
};