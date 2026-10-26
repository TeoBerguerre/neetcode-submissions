class Solution {
    bool ok(vector<int>& w, int days, int cap) {
        int need = 1, cur = 0;
        for (int x : w) {
            if (cur + x > cap) { need++; cur = 0; }
            cur += x;
        }
        return need <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while (lo < hi) {
            int m = (lo + hi) / 2;
            if (ok(weights, days, m)) hi = m; else lo = m + 1;
        }
        return lo;
    }
};