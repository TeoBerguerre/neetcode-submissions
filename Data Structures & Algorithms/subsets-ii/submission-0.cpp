class Solution {
    vector<vector<int>> res;
    vector<int> cur;
    void go(vector<int>& a, int start) {
        res.push_back(cur);
        for (int i = start; i < (int)a.size(); i++) {
            if (i > start && a[i] == a[i - 1]) continue;
            cur.push_back(a[i]); go(a, i + 1); cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        res.clear(); cur.clear(); go(nums, 0); return res;
    }
};