class Solution {
    vector<vector<int>> res;
    vector<int> cur;
    void go(vector<int>& a, int i, int rem) {
        if (rem == 0) { res.push_back(cur); return; }
        if (i == (int)a.size() || rem < 0) return;
        cur.push_back(a[i]); go(a, i, rem - a[i]); cur.pop_back();
        go(a, i + 1, rem);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res.clear(); cur.clear(); go(nums, 0, target); return res;
    }
};