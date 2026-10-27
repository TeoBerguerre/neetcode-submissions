class Solution {
    public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    bool g[3] = {false, false, false};
    for (auto& t : triplets) {
    if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) continue;
    for (int i = 0; i < 3; i++) if (t[i] == target[i]) g[i] = true;
    }
    return g[0] && g[1] && g[2];
    }
    };