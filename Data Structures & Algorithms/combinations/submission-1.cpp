class Solution {
    public:
    void go(int start, int n, int k, vector<int>& cur, vector<vector<int>>& res) {
    if ((int)cur.size() == k) { res.push_back(cur); return; }
    for (int i = start; i <= n; i++) { cur.push_back(i); go(i + 1, n, k, cur, res); cur.pop_back(); }
    }
    vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> cur;
    go(1, n, k, cur, res);
    return res;
    }
    };