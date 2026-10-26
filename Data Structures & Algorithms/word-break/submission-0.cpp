class Solution {
    public:
    bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<char> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    for (auto& w : wordDict)
    if (i + (int)w.size() <= n && dp[i + w.size()] && s.compare(i, w.size(), w) == 0) { dp[i] = 1; break; }
    return dp[0];
    }
    };