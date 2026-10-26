class Solution {
    vector<vector<int>> res;
    vector<int> cur;
    void go(int start, int n, int k) {
        if ((int)cur.size() == k) { res.push_back(cur); return; }
        for (int i = start; i <= n; i++) { cur.push_back(i); go(i + 1, n, k); cur.pop_back(); }
    }
public:
    vector<vector<int>> combine(int n, int k) { res.clear(); cur.clear(); go(1, n, k); return res; }
};