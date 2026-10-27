class Solution {
    public:
    void go(vector<int>& c, int start, int t, vector<int>& cur, vector<vector<int>>& res) {
    if (t == 0) { res.push_back(cur); return; }
    for (int i = start; i < (int)c.size() && c[i] <= t; i++) {
    if (i > start && c[i] == c[i - 1]) continue;
    cur.push_back(c[i]); go(c, i + 1, t - c[i], cur, res); cur.pop_back();
    }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> cur;
    go(candidates, 0, target, cur, res);
    return res;
    }
    };