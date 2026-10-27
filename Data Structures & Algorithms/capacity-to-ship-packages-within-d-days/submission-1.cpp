class Solution {
    public:
    int shipWithinDays(vector<int>& weights, int days) {
    int l = *max_element(weights.begin(), weights.end()), r = 0;
    for (int w : weights) r += w;
    while (l < r) {
    int m = l + (r - l) / 2, need = 1, load = 0;
    for (int w : weights) { if (load + w > m) { need++; load = 0; } load += w; }
    if (need <= days) r = m; else l = m + 1;
    }
    return l;
    }
    };