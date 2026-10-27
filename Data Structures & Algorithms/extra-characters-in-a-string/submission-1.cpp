class Solution {
    public:
    int minExtraChar(string s, vector<string>& dictionary) {
    unordered_set<string> d(dictionary.begin(), dictionary.end());
    int n = s.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
    dp[i] = 1 + dp[i + 1];
    for (int j = i + 1; j <= n; j++) if (d.count(s.substr(i, j - i))) dp[i] = min(dp[i], dp[j]);
    }
    return dp[0];
    }
    };