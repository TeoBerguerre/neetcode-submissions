class Solution {
    public:
    int characterReplacement(string s, int k) {
    int cnt[26] = {0}, l = 0, maxf = 0, best = 0;
    for (int r = 0; r < (int)s.size(); r++) {
    maxf = max(maxf, ++cnt[s[r] - 'A']);
    while (r - l + 1 - maxf > k) cnt[s[l++] - 'A']--;
    best = max(best, r - l + 1);
    }
    return best;
    }
    };