class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto d = [](const vector<int>& p) { return p[0] * p[0] + p[1] * p[1]; };
        sort(points.begin(), points.end(), [&](auto& a, auto& b) { return d(a) < d(b); });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};