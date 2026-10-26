class Solution {
    unordered_set<string> dict;
    vector<string> res;
    void go(const string& s, int i, string cur) {
        if (i == (int)s.size()) { res.push_back(cur); return; }
        for (int j = i + 1; j <= (int)s.size(); j++) {
            string w = s.substr(i, j - i);
            if (dict.count(w)) go(s, j, cur.empty() ? w : cur + " " + w);
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        res.clear(); go(s, 0, ""); return res;
    }
};