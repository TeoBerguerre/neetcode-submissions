class Solution {
    public:
    void go(vector<int>& c, int i, int t, vector<int>& cur, vector<vector<int>>& res) {
    if (t == 0) { res.push_back(cur); return; }
    if (i == (int)c.size() || t < 0) return;
    cur.push_back(c[i]); go(c, i, t - c[i], cur, res); cur.pop_back();
    go(c, i + 1, t, cur, res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    vector<int> cur;
    go(nums, 0, target, cur, res);
    return res;
    }
    };