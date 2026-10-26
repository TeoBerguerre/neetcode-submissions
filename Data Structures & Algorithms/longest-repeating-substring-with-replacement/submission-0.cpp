class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[128] = {0};
        int l = 0, maxf = 0, best = 0;
        for (int r = 0; r < (int)s.size(); r++) {
            maxf = max(maxf, ++cnt[(int)s[r]]);
            while (r - l + 1 - maxf > k) cnt[(int)s[l++]]--;
            best = max(best, r - l + 1);
        }
        return best;
    }
};