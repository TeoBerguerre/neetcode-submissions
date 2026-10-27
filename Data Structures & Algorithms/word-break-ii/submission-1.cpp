class Solution {
    public:
    unordered_set<string> dict;
    void go(const string& s, int start, string cur, vector<string>& res) {
    if (start == (int)s.size()) { res.push_back(cur); return; }
    for (int end = start + 1; end <= (int)s.size(); end++) {
    string w = s.substr(start, end - start);
    if (dict.count(w)) go(s, end, cur.empty() ? w : cur + " " + w, res);
    }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    dict = unordered_set<string>(wordDict.begin(), wordDict.end());
    vector<string> res;
    go(s, 0, "", res);
    return res;
    }
    };