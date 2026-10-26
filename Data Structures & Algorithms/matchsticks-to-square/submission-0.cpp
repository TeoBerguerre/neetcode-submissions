class Solution {
    bool go(vector<int>& a, int i, array<int, 4>& sides, int target) {
        if (i == (int)a.size()) return true;
        for (int s = 0; s < 4; s++) {
            if (sides[s] + a[i] > target) continue;
            bool seen = false;
            for (int t = 0; t < s; t++) if (sides[t] == sides[s]) { seen = true; break; }
            if (seen) continue;
            sides[s] += a[i];
            if (go(a, i + 1, sides, target)) return true;
            sides[s] -= a[i];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) return false;
        sort(matchsticks.rbegin(), matchsticks.rend());
        array<int, 4> sides{};
        return go(matchsticks, 0, sides, sum / 4);
    }
};