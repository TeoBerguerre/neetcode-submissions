class Solution {
    public:
    void go(vector<int>& a, int start, vector<int>& cur, vector<vector<int>>& res) {
    res.push_back(cur);
    for (int i = start; i < (int)a.size(); i++) {
    if (i > start && a[i] == a[i - 1]) continue;
    cur.push_back(a[i]); go(a, i + 1, cur, res); cur.pop_back();
    }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> cur;
    go(nums, 0, cur, res);
    return res;
    }
    };