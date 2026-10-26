class Solution {
    vector<vector<int>> res;
    vector<int> cur;
    void go(vector<int>& a, int start, int rem) {
        if (rem == 0) { res.push_back(cur); return; }
        for (int i = start; i < (int)a.size() && a[i] <= rem; i++) {
            if (i > start && a[i] == a[i - 1]) continue;
            cur.push_back(a[i]); go(a, i + 1, rem - a[i]); cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        res.clear(); cur.clear(); go(candidates, 0, target); return res;
    }
};